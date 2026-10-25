#include "../common/types.h"
extern "C" s32 func_002ff3fc(...);

u16 func_001ae270(s8* text) {
    u16 crc = 0xffff;
    u32 length = func_002ff3fc(text);
    s8* cursor = text + length - 1;
    for (u32 index = 0; index < length; index++) {
        crc ^= *cursor-- << 8;
        for (s32 bit = 7; bit >= 0; bit--) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc = crc << 1;
            }
        }
    }
    crc = ~crc;
    return crc;
}
