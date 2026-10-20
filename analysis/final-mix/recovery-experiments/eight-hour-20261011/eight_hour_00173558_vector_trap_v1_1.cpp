#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_001a7888(f32,f32,Quad*,Quad*,s32);
extern "C" Quad D_01c5f480;
void func_00173558(ScriptCell*record){
 Quad temporary;
 func_001a7888(record[1].value,record[2].value,&temporary,record[0].quad,1);
 register Quad*destination asm("$15")=&D_01c5f480;
 // Keep the native self-assignment test while copying all sixteen bytes.
 asm("":"+r"(destination));
 if(&temporary!=destination){register Quad value asm("$8")=temporary;asm("":"+r"(value));*destination=value;}
 record[0].quad=destination;
}
