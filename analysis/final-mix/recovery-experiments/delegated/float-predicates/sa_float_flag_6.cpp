#include "../common/types.h"
void func_00148638(f32 value,u64 unused,u32 object)
{
  u32 base=*(u32 *)(object+0x114);
  u8 previous=*(u8 *)(object+0x10d);
  f32 last=*(f32 *)(base+0x38);
  f32 middle=*(f32 *)(base+0x3c);
  u8 result;
  if(*(f32 *)(base+0x44)<value) result=2;
  else if(*(f32 *)(base+0x40)<value) { asm("" : : "f"(middle)); result=previous; }
  else if(middle<value) result=1;
  else if(last<value) result=previous;
  else result=0;
  *(u8 *)(object+0x10d)=result;
}

