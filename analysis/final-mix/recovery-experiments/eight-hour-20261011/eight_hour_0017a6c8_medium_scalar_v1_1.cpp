#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32 D_0034e948;extern "C" u32 func_0019ba60(u32);
bool func_0017a6c8(){u32 result=0;if(func_0019ba60(D_0034e948)){u8*object=(u8*)D_0034e948;result=(*(u32*)(object+0x160)&0x4000)!=0;}return result;}
