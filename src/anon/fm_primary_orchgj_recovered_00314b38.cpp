#include "../common/types.h"

u8* func_00314b38(u8* data, s64* result) {
    u32 shift = 0;
    u64 value = 0;
    u8 byte;
    do {
        byte = *data++;
        s32 part = (byte & 0x7f) << shift;
        value |= part;
        shift += 7;
    } while (byte & 0x80);
    if (shift < 64 && (byte & 0x40)) {
        value |= ~(u64)0 << shift;
    }
    *result = (s64)value;
    return data;
}
