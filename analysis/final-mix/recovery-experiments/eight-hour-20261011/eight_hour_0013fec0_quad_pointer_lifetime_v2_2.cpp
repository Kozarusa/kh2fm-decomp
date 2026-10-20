#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0013fd10();
extern "C" void func_0013fd78(u8*);
void func_0013fec0(u8*object){*(f32*)(object+80)=func_0013fd10();func_0013fd78(object);register Quad*source asm("$15")=(Quad*)(object+96);object+=16;asm("":"+r"(source),"+r"(object));if((Quad*)object!=source){*(Quad*)object=*source;}}

