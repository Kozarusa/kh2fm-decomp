#include "../common/types.h"
extern "C" s32 D_00354688;
extern "C" s32 D_0035468c;
extern "C" void func_00223e98(f32, f32, s32, u8*, u8, u8, s32);

void func_0020cf60(s32 unused, u8* object) {
    if (D_00354688 != 0) {
        if (D_0035468c > 0) {
            s32 value = *(s32*)(object + 4);
            u8 first = object[0x1c];
            u8 second = object[0x1d];
            s32 last = *(s32*)(object + 0x14);
            asm volatile("" ::: "memory"); // why: keeps integer argument loads before float loads
            func_00223e98(*(f32*)(object + 0xc), *(f32*)(object + 0x10), value, object + 8, first, second, last);
        }
    }
}
