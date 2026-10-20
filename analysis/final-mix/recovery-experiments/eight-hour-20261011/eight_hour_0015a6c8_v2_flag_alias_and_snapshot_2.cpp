#include "../common/types.h"
struct Configuration { u32 words[5]; };
extern "C" Configuration D_0034aa70;
union WordByteFlag { u32 word; u8 bytes[4]; };
extern "C" WordByteFlag D_0034aa40;
void func_0015a6c8(Configuration* source)
{
 u32* input=source->words;
 u32* output=D_0034aa70.words;
 output[0]=input[0];
 output[1]=input[1];
 output[2]=input[2];
 output[3]=input[3];
 u32 finalValue=input[4];
 D_0034aa40.bytes[0]=1;
 output[4]=finalValue;
}
