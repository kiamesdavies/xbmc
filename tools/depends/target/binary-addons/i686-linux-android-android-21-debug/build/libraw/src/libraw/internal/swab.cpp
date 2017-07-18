#if defined(TARGET_ANDROID) || defined(ANDROID)

#include "internal/swab.h"

#include <stdint.h>

void swab(const void *p_src, void *p_dst, ssize_t n)
{
  if (n < 0)
    return;

  for (ssize_t i = 0; i < n - 1; i += 2)
  {
    uint8_t tmp = static_cast<const uint8_t*>(p_src)[i + 0];
    static_cast<uint8_t*>(p_dst)[i + 0] = static_cast<const uint8_t*>(p_src)[i + 1];
    static_cast<uint8_t*>(p_dst)[i + 1] = tmp;
  }
}

#endif
