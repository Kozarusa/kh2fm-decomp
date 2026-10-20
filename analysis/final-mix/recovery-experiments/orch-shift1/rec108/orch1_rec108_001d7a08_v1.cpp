#include "../common/types.h"
extern "C" void func_001d7b10();

void func_001d7a08(s32 object, s32 value) {
    s32 count = 3;
    s32 *entry = (s32*)object;
    do {
        count--;
        if (entry[1] == value) {
            entry[1] = 0;
            func_001d7b10();
            return;
        }
        entry += 2;
    } while (count >= 0);
}