#include "../common/types.h"

s32* func_001bfd60(s32* entry, s32 key) {
    s32* free_slot = 0;
    s32 index = 0;
    register s32 more asm("$15");
    do {
        s32 value = *entry;
        if (value == key) {
            return entry;
        }
        s32 flag;
        asm("xori %0,%1,0" : "=&r"(flag) : "r"(value)); // why: original keeps a xori with immediate 0 that the compiler folds away
        if (flag == 0) {
            free_slot = entry;
        }
        index = index + 1;
        entry = entry + 4;
        more = index < 8; // why: original loop compare lands in t7 ($15)
    } while (more);
    *free_slot = key;
    return free_slot;
}
