#include "../common/types.h"

u8* func_00316f70(u8* input, s64* output) {
    u8 byte;
    u32 shift = 0;
    s64 value = 0;
    do {
        byte = *input;
        input = input + 1;
        value |= (s64)(s32)((u32)(byte & 0x7f) << shift);
        shift = shift + 7;
    } while ((byte & 0x80) != 0);
    if ((shift < 64) && ((byte & 0x40) != 0)) {
        value |= (s64)(~(u64)0 << shift);
    }
    *output = value;
    return input;
}
