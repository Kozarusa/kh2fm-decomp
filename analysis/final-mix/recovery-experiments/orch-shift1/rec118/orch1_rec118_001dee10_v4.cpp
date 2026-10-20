#include "../common/types.h"
struct Block16 { s32 word[4]; };
extern "C" void func_001e0158(s32);
extern "C" void func_001e01b8(u32);

void func_001dee10(s32 object) {
    if ((*(u32*)(object + 0x5c) & 4) != 0) {
        s32 pointer = *(s32*)(object + 0x58);
        if (pointer != 0) {
            Block16* end = (Block16*)(pointer + 0x40);
            Block16* base = (Block16*)(pointer + 0x20);
            if (pointer != -0x20) {
                do {
                } while (base != end--);
            }
            func_001e0158(pointer);
            asm volatile("" ::: "memory");
        }
    } else {
        if ((*(u32*)(object + 0x5c) & 8) != 0) {
            func_001e01b8(*(u32*)(object + 0x58));
            asm volatile("" ::: "memory");
        }
    }
}

