#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_00192800(u64,u64,u32*);
void func_00192818(u64 first,u64 second,u32*source){u32 snapshot[6];snapshot[0]=source[0];snapshot[1]=source[1];snapshot[2]=source[2];snapshot[3]=source[3];snapshot[4]=source[4];snapshot[5]=source[5];func_00192800(first,second,snapshot);}
