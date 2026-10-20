#include "../common/types.h"
struct Masks { u64 reserved[2]; u64 values[256]; };
extern "C" Masks D_0034a970;
extern "C" u32 func_00242ce8(void);
bool func_00158548(u64 *flags)
{
  u32 index=(func_00242ce8()^1)&255;
  register u8 *base asm("$15")=(u8 *)&D_0034a970;
  asm("" : "+r"(base) : "r"(index));
  return (*flags&*(u64 *)(base+index*8+16))!=0;
}
