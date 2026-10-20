#include "../common/types.h"
extern "C" u8 D_00350ce0;
extern "C" f32 D_0036d858;
extern "C" void func_00185b00(u32*,u64,u64);
void func_001ae9a0(u32* object,u64 second,u64 third)
{
 func_00185b00(object,second,third);
 *object=(u32)&D_00350ce0;
 object[0x162]|=0x400;
 object[0x1de]=0;
 *(f32*)(object+0x1dd)=D_0036d858;
 object[0x2af]|=0x8404;
}
