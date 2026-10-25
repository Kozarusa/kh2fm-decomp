#include "../common/types.h"
extern "C" u32 func_00294000(u64);
// why: extern "C" because the probe linker script defines only the plain symbol; type from the recovered definition s32 func_00294480(u8*)
extern "C" s32 func_00294480(u8* object);

s32 func_002ae1b0(s32 mode, s32 kind) {
    s32 key = kind;
    if (mode != 0) {
        key = 16;
    }
    s32 index = 0;
    register s32 found asm("$20") = 0; // why: original keeps the found flag in s4 and the table in s3
    s32 result = 1;
    u32 table = func_00294000(5);
    s32 count = *(s32*)(table + 8);
    u8* first = (u8*)(table + 16);
    if (count > 0) {
        u8* entry = first;
        do {
            if (*(s8*)(entry + 4) != key) {
                if (found != 0) {
                    break;
                }
            } else {
                if (found == 0) {
                    found = 1;
                }
                if (func_00294480(entry) == 0) {
                    result = 0;
                    break;
                }
                count = *(s32*)(table + 8);
            }
            index++;
            entry += 12;
        } while (index < count);
    }
    return result;
}
