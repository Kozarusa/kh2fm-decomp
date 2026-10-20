#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0016af58(Quad*,u32);
extern "C" Quad D_01c5f480;
void func_00171518(ScriptCell*record){
 Quad temporary;
 func_0016af58(&temporary,*(u32*)(record[0].object+4));
 Quad*destination=&D_01c5f480;
 // Keep the native self-assignment test while copying all sixteen bytes.
 asm("":"+r"(destination));
 if(&temporary!=destination){register Quad value asm("$8")=temporary;asm("":"+r"(value));*destination=value;}
 record[0].quad=destination;
}
