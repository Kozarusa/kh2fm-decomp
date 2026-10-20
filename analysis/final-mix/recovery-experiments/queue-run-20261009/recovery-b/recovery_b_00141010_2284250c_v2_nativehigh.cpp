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
    asm("" : "+r"(high));
    register State *state asm("$16")=(State *)(high-30960);
    asm("" : "+r"(state));
    register u32 object asm("$14")=state->object;
    asm("" : "+r"(object));
    if(object!=0) {
      register f32 *argument asm("$15")=&D_0036ae80;
      asm("" : "+r"(argument));
      func_001ad990(0.0f,*argument,value,object+0x834);
      state->reset=0;
    }
  }
}
