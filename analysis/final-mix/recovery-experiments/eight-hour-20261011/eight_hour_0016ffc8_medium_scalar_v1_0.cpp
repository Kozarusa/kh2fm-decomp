#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
s32 func_0016ffc8(u8*object){s32 original=*(s32*)(object+40);s32 result=original;if(original<0 && object[0]==0){s32 candidate=*(s32*)(object+56);if((u32)(candidate-2300)<=99 || (u32)(candidate-2410)<=9 || (u32)(candidate-2420)<=9)result=candidate;}return result;}
