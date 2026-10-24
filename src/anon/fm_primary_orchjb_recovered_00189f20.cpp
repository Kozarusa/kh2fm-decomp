#include "../common/types.h"

void func_00189f20(u8* data, void (*callback)(u16*, void*), void* argument, f32 value) {
    u16* entry = (u16*)(data + 4);
    s32 index;
    for (index = 0; index < data[0]; index++) {
        u32 flag = 0;
        if ((f32)entry[0] <= value) {
            if (entry[1] == 0xffff) {
                flag = 1;
            } else {
                flag = 0;
                if (value < (f32)entry[1]) {
                    flag = 1;
                }
            }
        }
        if (flag & 0xff) {
            callback(entry, argument);
        }
        entry = entry + ((u8*)entry)[5] + 3;
    }
}
