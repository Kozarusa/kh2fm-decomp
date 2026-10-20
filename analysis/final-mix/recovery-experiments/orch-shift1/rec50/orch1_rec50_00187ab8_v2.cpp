#include "../common/types.h"
extern "C" s32 func_002ff1a4(void*, s32);

s32* func_00187ab8(s32* entry, void* name) {
    s32* result = 0;
    if (entry != 0) {
        s32 index = 0;
        do {
            if (*entry != 0 && func_002ff1a4(name, *entry) == 0) {
                result = entry;
                break;
            }
            index++;
            entry += 8;
            result = 0;
        } while (index < 128);
    }
    return result;
}