#include "../common/types.h"
struct ByteList {
    s8 items[3];
};
extern "C" u32 func_002632d0(...);
extern "C" ByteList D_00373268;

s32 func_002635d8() {
    ByteList list = D_00373268;
    s32 result = 0;
    u8 value = ((u8*)func_002632d0())[2];
    s32 index = 0;
    if (list.items[0] >= 0) {
        do {
            if (value == list.items[index]) { result = 1; break; }
            index++;
        } while (list.items[index] >= 0);
    }
    return result;
}
