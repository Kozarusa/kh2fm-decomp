#include "../common/types.h"
extern "C" s32 func_00106520(s32, s32);

void func_00132720(u8* object, u8* entry) {
    if (*(u8**)(object + 632) == entry) {
        return;
    }
    if (entry != 0) {
        *(u32*)(object + 20) |= 1;
        asm volatile("" ::: "memory"); // why: keeps store order
        u32 value = func_00106520(*(u16*)(entry + 2), *(u16*)(entry + 4) + 1);
        *(f32*)(object + 640) = (f32)value;
        *(s32*)(object + 644) = 0;
    }
    *(u8**)(object + 636) = entry;
    *(u8**)(object + 632) = entry;
}
