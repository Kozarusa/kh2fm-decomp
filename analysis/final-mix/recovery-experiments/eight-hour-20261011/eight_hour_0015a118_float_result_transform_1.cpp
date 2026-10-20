#include "../common/types.h"
extern "C" f32 D_0034aa44;
extern "C" f32 func_0015a098();
extern "C" f32 func_0017ce10(f32);
void func_0015a118(f32* object)
{
 f32 value=func_0015a098();
 register f32 result asm("$f0")=value+D_0034aa44;
 asm("" : "+f"(result));
 object[20]=func_0017ce10(result);
}
