#include "../common/types.h"
extern "C" s32 D_003a99f0;
void func_00148a68(u32 object,u32 item)
{
  register s32 *base asm("$11")=&D_003a99f0;
  asm("" : "+r"(base));
  register u32 index asm("$12")=*(u8 *)(item+0x11f);
  register s32 *cursor asm("$13")=base+index;
  asm("" : "+r"(cursor), "+r"(index));
  while(*cursor!=0) { ++cursor; ++index; }
  base[index]=item;
  ++*(u32 *)(object+0x537c);
}
