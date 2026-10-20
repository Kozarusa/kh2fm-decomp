#include "../common/types.h"
struct State { u8 reserved[0x40]; u32 reset; u32 object; };
extern "C" State D_00348710;
extern "C" f32 D_0036ae80;
extern "C" s32 func_00141080(void);
extern "C" void func_001ad990(f32,f32,f32,u32);
void func_00141010(f32 value)
{
  if(func_00141080()!=0 && D_00348710.object!=0) {
    func_001ad990(0.0f,D_0036ae80,value,D_00348710.object+0x834);
    D_00348710.reset=0;
  }
}
