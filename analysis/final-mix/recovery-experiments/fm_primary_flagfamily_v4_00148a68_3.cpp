#include "../common/types.h"
extern "C" s32 D_003a99f0;
void func_00148a68(u32 object,u32 item)
{
  register s32 *base asm("$11")=&D_003a99f0;
  asm volatile("" : "+r"(base));
  u32 index=*(u8 *)(item+0x11f);
  s32 *cursor=base+index;
  while(*cursor!=0) { ++cursor; ++index; }
  base[index]=item;
  ++*(u32 *)(object+0x537c);
}
