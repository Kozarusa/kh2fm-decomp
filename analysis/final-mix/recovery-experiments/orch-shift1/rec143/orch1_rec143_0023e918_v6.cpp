#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union Vector { Quad quad; f32 values[4]; };
void func_0023e918(u8* object,u32 index,f32 x,f32 y,f32 z) {
    Vector value;
    index += (u32)object;
    u8* pointer=object+*(u8*)(index+2916)*320+1664;
    value.values[3]=0;
    value.values[0]=x;
    value.values[1]=y;
    value.values[2]=z;
    if(pointer!=(u8*)&value) {
        register Quad copy asm("$8")=value.quad; // why: original quad copy uses t0
        *(Quad*)pointer=copy;
    }
}


