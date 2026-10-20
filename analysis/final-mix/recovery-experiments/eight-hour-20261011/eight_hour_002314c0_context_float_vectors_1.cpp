#include "../common/types.h"
extern "C" f32 D_0035db20[7];
void func_002314c0(f32* input)
{
 register f32* output asm("$15")=D_0035db20;
 asm("" : "+r"(output));
 output[0]=input[0];
 output[1]=input[1];
 output[2]=input[2];
 output[4]=input[3];
 output[5]=input[4];
 output[6]=input[5];
}
