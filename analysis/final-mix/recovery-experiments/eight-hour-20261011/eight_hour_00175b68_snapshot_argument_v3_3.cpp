#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" void func_0016b010(u8*,Quad*);extern "C" void func_00198690(u8*);typedef u32(*CheckCallback)(u8*);
void func_00175b68(u8*object){Quad snapshot;CheckCallback check=((CheckCallback*)*(u32*)object)[33];if(check(object)){register Quad*source asm("$15")=(Quad*)(object+16);asm volatile("":"+r"(source));register Quad value asm("$8")=*(volatile Quad*)source;asm("":"+r"(value));snapshot=value;u8*receiver=object;asm("":"+r"(receiver):"m"(snapshot));register Quad*out asm("$5")=&snapshot;asm("":"+r"(out):"m"(snapshot));func_0016b010(receiver,out);}func_00198690(object);}

