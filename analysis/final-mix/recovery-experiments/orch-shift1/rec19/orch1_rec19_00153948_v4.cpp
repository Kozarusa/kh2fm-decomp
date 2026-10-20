#include "../common/types.h"
extern "C" u8* D_0034a790;
extern "C" s32 D_0034a77c;
extern "C" u8* D_0034a778;

void func_00153948(u8 id) {
    if (D_0034a790 != 0) {
        s32 count = D_0034a77c;
        s32 index = 0;
        if (index < count) {
            // why: pins the stride offset to t5 like the original
            register s32 offset asm("$13") = 0;
            do {
                s32 entry = *(s32*)(offset + (u32)D_0034a778);
                offset += 24;
                if (entry == id) {
                    *(u8*)((index << 6) + (u32)D_0034a790 + 0x30) = 0;
                }
                index++;
            } while (index < count);
        }
    }
}


