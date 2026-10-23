#include "../common/types.h"
extern "C" u32 func_00242d58(void);
extern "C" u8 D_0034a970;

bool func_001584a0(u64 *flags)
{
  u32 index=(func_00242d58()^1)&255;
  return (*flags & *(u64 *)(&D_0034a970+index*8))!=0;
}
