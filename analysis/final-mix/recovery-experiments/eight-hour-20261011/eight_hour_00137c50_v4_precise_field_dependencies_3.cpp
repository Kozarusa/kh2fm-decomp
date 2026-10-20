#include "../common/types.h"
extern "C" void func_001391c8(u32*,u32,u32);
void func_00137c50(u32* object)
{
 u32* fields=object;
 fields[0xa72]=0;
 register u32 one asm("$14")=1;
 asm("" : "+r"(one) : "m"(fields[0xa72]));
 fields[0xa70]=one;
 asm("" : "+r"(one) : "m"(fields[0xa70]));
 fields[8]=one;
 fields[12]=0;
 fields[13]=0;
 asm ("" : "+r"(fields) : "m"(fields[12]),"m"(fields[13]),"m"(fields[8]),"m"(fields[0xa70]));
 fields[0xa71]=0;
 func_001391c8(object,0x2b5c,0);
}
