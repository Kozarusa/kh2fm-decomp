#include "../common/types.h"
extern "C" u32 func_001dcb98(u64, s32);

void func_001942b8(s32 base) {
    s32* cursor = (s32*)(base + 0x7b8);
    s32 count = 15;
    do {
        s32 entry = *cursor;
        cursor++;
        if (entry != 0) {
            func_001dcb98(entry, base + 0x758);
        }
        count--;
    } while (count >= 0);
}
