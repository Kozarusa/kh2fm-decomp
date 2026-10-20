#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0017d5e8(f32,Quad*,Quad*);
extern "C" Quad D_004f62a0;
void func_0016d640(ScriptCell*record){
 Quad temporary;
 func_0017d5e8(record[1].value,&temporary,record[0].quad);
 register Quad*destination asm("$15")=&D_004f62a0;
 // Keep the native self-assignment test while copying all sixteen bytes.
 asm("":"+r"(destination));
 if(&temporary!=destination){*destination=temporary;}
 record[0].quad=destination;
}
