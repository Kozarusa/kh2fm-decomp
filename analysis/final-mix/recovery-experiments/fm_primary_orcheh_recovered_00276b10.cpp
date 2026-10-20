#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u8* D_0035f21c;
typedef u32 (*Callback)(u8*);

u32 func_00276b10() {
    s32 offset = 0;
    s32 count = 31;
    u32 result;
    do {
        result = func_00139d78(D_0035f21c + offset + 0xa998);
        if (result) {
            u8* object = (u8*)(offset + (u32)D_0035f21c + 0xa998);
            register Callback* table asm("$14") = *(Callback**)object; // why: original loads vtable into t6
            register Callback callback asm("$15") = table[5]; // why: original indirect call target is t7
            result = callback(object);
        }
        count--;
        offset += 408;
    } while (count >= 0);
    return result;
}
