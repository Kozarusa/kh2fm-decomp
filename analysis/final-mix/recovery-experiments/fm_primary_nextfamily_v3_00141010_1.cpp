#include "../common/types.h"
struct State { u8 reserved[0x40]; u32 reset; u32 object; };
extern "C" State D_00348710;
extern "C" f32 D_0036ae80;
extern "C" s32 func_00141080(void);
extern "C" void func_001ad990(f32,f32,f32,u32);
void func_00141010(f32 value)
{
  if(func_00141080()!=0) {
    register State *state asm("$16")=&D_00348710;
    asm volatile("" : "+r"(state));
    if(state->object!=0) {
      register f32 *argument asm("$15")=&D_0036ae80;
      asm volatile("" : "+r"(argument));
      func_001ad990(0.0f,*argument,value,state->object+0x834);
      state->reset=0;
    }
  }
}
