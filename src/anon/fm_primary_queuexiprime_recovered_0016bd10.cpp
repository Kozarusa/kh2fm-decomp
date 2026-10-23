#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32*func_0017aab8(u64);typedef void(*BindCallback)(u32*,u8*);

// Preserve original registry aliases.
void func_0016bd10(u8*object,u64 key) asm("_ZN2YS6ACTION3GetENS0_2IDE");

void func_0016bd10(u8*object,u64 key){u32*receiver=func_0017aab8(key);((BindCallback*)*receiver)[0](receiver,object);*(u32**)(object+12)=receiver;}
