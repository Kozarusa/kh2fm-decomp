#include "../common/types.h"
extern "C" u8 D_003625e0;
extern "C" void func_002d0ea8(u32*,u64,u64,u64);
void func_002d9730(u32* object,u64 second,u64 third,u64 fourth)
{
 func_002d0ea8(object,second,third,fourth);
 object[0x326]=0;
 *(f32*)(object+0x2fc)=0.0f;
 *(u8*)(object+0x301)=1;
 *object=(u32)&D_003625e0;
 *(f32*)(object+0x2fd)=0.0f;
 *(u8*)(object+0x2ff)=1;
 object[0x300]=0;
 object[0x324]=0;
 object[0x325]=0;
}
