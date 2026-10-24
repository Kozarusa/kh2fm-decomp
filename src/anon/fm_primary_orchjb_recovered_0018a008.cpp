#include "../common/types.h"

void func_0018a008(f32 low, f32 high, u8* data, void (*callback)(u16*, void*), void* argument) {
    u16* entry = (u16*)(data + *(u16*)(data + 2));
    s32 index;
    for (index = 0; index < data[1]; index++) {
        f32 value = (f32)(s32)*entry;
        s32 flag = 0;
        if (low < value && value <= high) {
            flag = 1;
        } else if (high < 0.0f && value == low) {
            flag = 1;
        }
        if ((flag & 0xff) != 0) {
            callback(entry, argument);
        }
        entry = (u16*)((u8*)entry + ((u8*)entry)[3] * 2 + 4);
    }
}
