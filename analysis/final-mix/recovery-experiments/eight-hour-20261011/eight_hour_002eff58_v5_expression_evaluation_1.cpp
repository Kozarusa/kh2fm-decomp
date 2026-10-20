#include "../common/types.h"
extern "C" f32 D_00376224;
bool func_002eff58(f32* object)
{
 register f32* scale asm("$15")=&D_00376224;
 asm("" : "+r"(scale));
 return *scale*(object[0x44]+object[0x45])<=object[7];
}
