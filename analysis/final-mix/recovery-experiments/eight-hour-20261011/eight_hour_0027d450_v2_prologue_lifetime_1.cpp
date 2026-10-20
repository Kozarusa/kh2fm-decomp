#include "../common/types.h"
extern "C" u32 func_00257770();
extern "C" u32 func_00139d78(u32);
extern "C" void func_0028da70(u32,s32);
void func_0027d450()
{
 register u32 object asm("$16")=func_00257770();
 asm("" : "+r"(object));
 func_00139d78(object);
 func_0028da70(object,234);
}
