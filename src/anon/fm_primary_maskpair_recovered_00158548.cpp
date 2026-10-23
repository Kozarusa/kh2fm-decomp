#include "../common/types.h"
extern "C" u8 D_0034a970;
extern "C" u32 func_00242ce8(void);

bool func_00158548(u64 *flags)
{
  u32 index=(func_00242ce8()^1)&255;
  u8 *slot=(u8 *)&D_0034a970+index*8;
  return (*flags&*(u64 *)(slot+16))!=0;
}
