#include "../common/types.h"
extern "C" u32 D_0034aa70[5];
extern "C" u8 D_0034aa40;
void func_0015a6c8(u32* input)
{
 register u32* output asm("$12")=D_0034aa70;
 asm("" : "+r"(output));
 output[0]=input[0];
 output[1]=input[1];
 output[2]=input[2];
 output[3]=input[3];
 D_0034aa40=1;
 output[4]=input[4];
}
