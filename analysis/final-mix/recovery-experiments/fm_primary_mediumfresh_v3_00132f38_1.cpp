#include "../common/types.h"
extern "C" s32 func_00132c68(void);
extern "C" s32 func_001325c8(u32,s32,u32);
void func_00132f38(u32 param_1)
{
  register u32 object asm("$17")=param_1;
  asm volatile("" : "+r"(object));
  register s32 base asm("$16")=func_00132c68();
  s32 index=func_001325c8(object,0,*(u32 *)(base+0x24));
  if(index>=0) {
    register u32 scaled asm("$14")=(u32)index*4;
    asm volatile("" : "+r"(scaled));
    register u32 address asm("$15")=base+*(u32 *)(base+0x1c)+scaled;
    asm volatile("" : "+r"(address));
    register u32 value asm("$14")=*(u32 *)address;
    asm volatile("" : "+r"(value));
    *(u32 *)(object+0x274)=base+value;
  }
}
