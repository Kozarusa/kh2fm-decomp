#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell {u32 word;f32 value;Quad*quad;u8*object;};
extern "C" Quad*func_001dc648(u32);
extern "C" void func_0017d050(Quad*,Quad*);
void func_0016e240(ScriptCell*record){Quad temporary;Quad*destination=func_001dc648(record[0].word);func_0017d050(&temporary,record[1].quad);if(destination!=&temporary){*destination=temporary;}}
