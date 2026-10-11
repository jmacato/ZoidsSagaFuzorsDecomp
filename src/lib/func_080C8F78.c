#define UNALIGNED(X, Y) \
  (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

char *
func_080C8F78 (char *dst0, const char *src0)
{
  char *dst = dst0;
  const char *src = src0;
  long *aligned_dst;
  const long *aligned_src;

  if (!UNALIGNED (src, dst))
    {
      aligned_dst = (long*)dst;
      aligned_src = (long*)src;

      while (!DETECTNULL(*aligned_src))
        {
          *aligned_dst++ = *aligned_src++;
        }

      dst = (char*)aligned_dst;
      src = (char*)aligned_src;
    }

  while (*dst++ = *src++)
    ;
  return dst0;
}
