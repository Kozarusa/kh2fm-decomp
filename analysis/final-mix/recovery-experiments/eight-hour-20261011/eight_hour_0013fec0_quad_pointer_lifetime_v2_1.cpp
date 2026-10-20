#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0013fd10();
extern "C" void func_0013fd78(u8*);
void func_0013fec0(u8*object){*(f32*)(object+80)=func_0013fd10();func_0013fd78(object);Quad*source=(Quad*)(object+96);object+=16;asm("":"+r"(source),"+r"(object));if((Quad*)object!=source){register Quad value asm("$8")=*source;asm("":"+r"(value));*(Quad*)object=value;}}

