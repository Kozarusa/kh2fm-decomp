#include "../common/types.h"
extern "C" f32 D_00375c8c;

f32 func_002d8d40(u8* object, f32* first, f32* second) {
    register f32* source asm("$15") = &D_00375c8c; // why: original keeps the formed address in t7
    asm("" : "+r"(source)); // why: keeps the full address formed before the separate lwc1
    register f32 offset asm("$f2") = *source; // why: original holds the offset in $f2
    register f32 sum asm("$f1") = *(f32*)(object + 0x1d8) + offset; // why: original forms the sum in $f1
    asm("" : "+f"(sum)); // why: keeps the sum in its bound register $f1
    *first = sum;
    f32 result = *(f32*)(object + 0x1d4) - offset;
    *second = result;
    return result;
}
