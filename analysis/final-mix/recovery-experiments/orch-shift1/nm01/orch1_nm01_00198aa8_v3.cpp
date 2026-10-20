#include "../common/types.h"

void func_00198aa8(s32 object, s32 index, s32 value, s32 slot) {
    if (slot == 0) {
        slot = -1;
        s32 entry = *(s32*)(object + 0x9b4);
        if (entry != 0) {
            slot = *(s16*)(entry + 2);
        }
    }
    s32 total = slot * 1000 + value;
    asm volatile("" : "+r"(total)); // why: keeps total add before the address add
    s32 scaled = index * 12;
    asm volatile("" : "+r"(scaled)); // why: forces addu object,scaled operand order
    *(s32*)(object + scaled + 0x9e4) = total;
}