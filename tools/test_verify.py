import contextlib
import hashlib
import importlib.util
import io
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock


TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))
spec = importlib.util.spec_from_file_location("verify", TOOLS / "verify.py")
verify = importlib.util.module_from_spec(spec)
spec.loader.exec_module(verify)
AGBCC = Path(os.environ.get("AGBCC", TOOLS.parents[1] / "agbcc/agbcc"))


@unittest.skipUnless(AGBCC.is_file(), "agbcc is required.")
class VerifyQualityTests(unittest.TestCase):
    def run_fixture(self, source, complete=False, native_data=False):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "cfg").mkdir()
            (root / "src/entry.c").write_text(source)
            work = root / "build"
            work.mkdir()
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}):
                data = verify.compile_region("entry", 0x1000, "c", AGBCC, work)
            regions = (("entry", 0x1000, 0x1000 + len(data), "c"),)
            (root / "cfg/functions.tsv").write_text(
                f"0x08001000\t0x{0x08001000 + len(data):08X}\tthumb\tfunc\troot\n"
                "0x08002000\t0x08002004\tarm\tfunc\troot\n")
            if native_data:
                (root / "cfg/functions.tsv").write_text(
                    f"0x08001000\t0x{0x08001000 + len(data):08X}\tthumb\tfunc\troot\n"
                    f"0x{0x08001000 + len(data) - 4:08X}\t0x{0x08001000 + len(data):08X}\tthumb\tfunc\troot\n")
            rom = bytearray(verify.ROM_SIZE)
            rom[0x1000:0x1000 + len(data)] = data
            rom_path = root / "original.gba"
            rom_path.write_bytes(rom)
            output_path = root / "rebuilt.gba"
            output_path.write_bytes(b"previous output")
            argv = ["verify", "--rom", str(rom_path), "--agbcc", str(AGBCC),
                    "--output", str(output_path)]
            if complete:
                argv.append("--require-all-c")
            with mock.patch.object(verify, "ROOT", root), \
                 mock.patch.object(verify, "REGIONS", regions), \
                 mock.patch.object(verify, "SOURCE_FILES", {"entry": "entry.c"}), \
                 mock.patch.object(verify, "ROM_SHA1", hashlib.sha1(rom).hexdigest()), \
                 mock.patch.object(sys, "argv", argv), \
                 contextlib.redirect_stdout(io.StringIO()) as output:
                status = verify.main()
            return status, output.getvalue(), output_path.read_bytes()

    def test_byte_exact_assembly_cannot_pass_or_replace_output(self):
        status, output, saved = self.run_fixture(
            'void entry(void) { asm volatile("nop"); }\n')
        self.assertEqual(status, 1)
        self.assertIn("1/1 matched", output)
        self.assertIn("FAIL C source quality", output)
        self.assertIn("assembly: 1 regions", output)
        self.assertEqual(saved, b"previous output")

    def test_c_array_cannot_count_as_decompiled_native_code(self):
        status, output, saved = self.run_fixture(
            "const unsigned short hidden_code[] = {0x4770, 0x46C0};\n"
            "unsigned entry(unsigned value) { return value; }\n",
            complete=True, native_data=True)
        self.assertEqual(status, 1)
        self.assertIn("1/1 matched", output)
        self.assertIn("FAIL compiled C coverage", output)
        self.assertEqual(saved, b"previous output")

    def test_completion_rejects_native_code_missing_from_regions(self):
        status, output, saved = self.run_fixture(
            "unsigned entry(unsigned value) { return value; }\n", complete=True)
        self.assertEqual(status, 1)
        self.assertIn("1/1 matched", output)
        self.assertIn("FAIL C completion", output)
        self.assertIn("0x08002000", output)
        self.assertEqual(saved, b"previous output")


if __name__ == "__main__":
    unittest.main()
