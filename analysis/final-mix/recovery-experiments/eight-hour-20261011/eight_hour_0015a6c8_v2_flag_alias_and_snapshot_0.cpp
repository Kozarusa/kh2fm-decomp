#include "../common/types.h"
extern "C" u32 D_0034aa70[5];
extern "C" u8 D_0034aa40;
void func_0015a6c8(u32* input)
{
 u32* output=D_0034aa70;
 output[0]=input[0];
 output[1]=input[1];
 output[2]=input[2];
 output[3]=input[3];
 u32 finalValue=input[4];
 D_0034aa40=1;
 output[4]=finalValue;
}
