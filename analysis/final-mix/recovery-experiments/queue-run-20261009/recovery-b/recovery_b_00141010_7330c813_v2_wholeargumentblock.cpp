#include "../common/types.h"
struct State { u8 reserved[0x40]; u32 reset; u32 object; };
extern "C" State D_00348710;
extern "C" f32 D_0036ae80;
extern "C" s32 func_00141080(void);
extern "C" void func_001ad990(f32,f32,f32,u32);
void func_00141010(f32 value)
{
  if(func_00141080()!=0) {
    register u32 high asm("$15")=0x350000;
    asm("" : : "r"(high));
    register State *state asm("$16")=(State *)(high-30960);
    asm("" : "+r"(state));
    register u32 object asm("$14")=state->object;
    asm("" : "+r"(object));
    if(object!=0) {
      f32 *argument;
      register f32 third asm("$f14");
      register f32 first asm("$f12");
      asm("mov.s %0,%3; lui %1,0x37; addiu %1,%1,-20864; mtc1 $0,%2" : "=f"(third),"=r"(argument),"=f"(first) : "f"(value),"r"(object) : "memory");
      func_001ad990(first,*argument,third,object+0x834);
      state->reset=0;
    }
  }
}
