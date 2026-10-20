#include "../common/types.h"

extern "C" u8* func_00132c68(u8*, s32);
extern "C" s32 func_001325c8(u8*, s32, s32);

void func_00132ec0(u8* object, s32 key) {
    u8* table = func_00132c68(object, key);
    if (table != 0) {
        s32 index = func_001325c8(object, 0xffff, key);
        if (index >= 0) {
            u8* entries = table + *(s32*)(table + 0x1c);
            *(u8**)(object + 0x274) = table + *(s32*)(entries + index * 4);
        }
    }
}
