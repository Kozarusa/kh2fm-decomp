#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);

void func_00198700(s32 object) {
    u32 flag;
    do {
        s32 next = func_001b9bc8(object);
        if (next == 0) {
            return;
        }
        object = next;
        flag = *(u32*)(next + 0x588) & 1;
    } while ((u8)flag == 0);
}
