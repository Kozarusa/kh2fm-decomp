#include "../common/types.h"
extern "C" u32 D_0035f3d4;
extern "C" u32 func_00138d60(...);
extern "C" u32 func_00192048(...);
u32 func_0028c0a0(u32* object,u32 value,u32 image,u32 message,s64 index,u32 mode) {
    u32 result=func_00138d60(object,D_0035f3d4,image,message,value,0,mode);
    object[3] |= 8;
    if (index >= 0) {
        result=func_00192048(index);
        object[102]=result;
    }
    register u32 color asm("$14") = 0x80e5e5e5; // why: original materializes final color in t6 before flag store.
    ((volatile u32*)object)[107]=1;
    ((volatile u32*)object)[105]=color;
    return result;
}


