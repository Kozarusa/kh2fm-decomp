#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0017d698(f32,Quad*,Quad*,u32);
extern "C" Quad D_004f62a0;
void func_0016d8d0(ScriptCell*record){
 Quad temporary;
 func_0017d698(record[2].value,&temporary,record[0].quad,record[1].word);
 Quad*destination=&D_004f62a0;
 // Keep the native self-assignment test while copying all sixteen bytes.
 asm("":"+r"(destination));
 if(&temporary!=destination){register Quad value asm("$8")=temporary;asm("":"+r"(value));*destination=value;}
 record[0].quad=destination;
}
