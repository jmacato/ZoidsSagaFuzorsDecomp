.PHONY: verify native quality c-complete test

ROM ?=
NATIVE_OUTPUT ?= Zoids Saga Fuzors Native.gba

verify:
	PYTHONDONTWRITEBYTECODE=1 python3 tools/verify.py --rom "$(ROM)"

native:
	PYTHONDONTWRITEBYTECODE=1 python3 tools/verify.py --rom "$(ROM)" --output "$(NATIVE_OUTPUT)"

quality:
	PYTHONDONTWRITEBYTECODE=1 python3 tools/c_quality.py

c-complete:
	PYTHONDONTWRITEBYTECODE=1 python3 tools/verify.py --rom "$(ROM)" --require-all-c

test:
	PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tools -p 'test_*.py' -v
