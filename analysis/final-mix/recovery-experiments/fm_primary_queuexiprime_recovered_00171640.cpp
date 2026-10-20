#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" Quad D_01c5f480;extern "C" void func_00185138(u32,Quad*,bool,f32);

void func_00171640(ScriptCell*record){Quad*destination=&D_01c5f480;func_00185138(*(u32*)(record[0].object+4),destination,record[2].word!=0,record[1].value);record[0].quad=destination;}
