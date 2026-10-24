#include "../common/types.h"
struct Block;
struct Owner;
extern "C" s32 D_0034ed00;
extern "C" Owner* D_01c60588[];
extern "C" Block* func_0019b380(Owner*, s32);

Block* func_00182e98(s32 key) {
    s32 index = 0;
    if (D_0034ed00 > 0) {
        Owner** base = D_01c60588;
        // why: keeps the table base in its own register before the +8 field offset is added
        asm("" : "+r"(base));
        Owner** entry = base + 2;
        do {
            Block* result = func_0019b380(*entry, key);
            entry += 3;
            if (result != 0) {
                return result;
            }
            index++;
        } while (index < D_0034ed00);
    }
    return 0;
}
