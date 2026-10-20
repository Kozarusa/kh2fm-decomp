#include "../common/types.h"
extern "C" f32 D_00376224;
bool func_002eff58(f32* object)
{
 register f32* scale asm("$15")=&D_00376224;
 asm("" : "+r"(scale));
 f32 first=object[0x44];
 f32 second=object[0x45];
 f32 factor=*scale;
 f32 limit=object[7];
 return factor*(first+second)<=limit;
}
