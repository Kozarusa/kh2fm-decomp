#include "../common/types.h"
extern "C" u32 func_00242ce8(void);
extern "C" u8 D_0034a980;
bool func_00158548(u64 *flags)
{
  u32 index=(func_00242ce8()^1)&255;
  return (*flags & *(u64 *)(&D_0034a980+index*8))!=0;
}
