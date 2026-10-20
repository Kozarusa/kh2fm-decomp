#include "../common/types.h"
struct Entry { u8* current; u8* replacement; };
extern "C" Entry* volatile D_0035dce8;
void func_00230878(u8* object) {
    register s32 value asm("$10") = *(s16*)(object + 4); // why: original retains comparison value in t2
    asm("" : "+r"(value)); // why: keeps comparison value in t2
    s32 count = 0;
    do {
        register Entry* entry asm("$13") = (Entry*)((count * 8) + (u32)D_0035dce8); // why: original keeps entry address in t5
        ++count;
        u8* pointer = entry->current;
        if(pointer && *(s16*)(pointer + 4) == value) {
            entry->replacement = object;
            return;
        }
    } while(count < 64);
}
