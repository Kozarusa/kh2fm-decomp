#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0017d698(Quad*,Quad*,u32,f32);
extern "C" Quad D_004f62a0;
void func_0016d8d0(ScriptCell*record){
 Quad temporary;
 func_0017d698(&temporary,record[0].quad,record[1].word,record[2].value);
 register Quad*destination asm("$15")=&D_004f62a0;
 // Keep the conditional sixteen-byte load out of the branch delay slot.
 asm("":"+r"(destination));
 if(&temporary!=destination){register Quad value asm("$8")=*(volatile Quad*)&temporary;asm("":"+r"(value));*destination=value;}
 record[0].quad=destination;
}
