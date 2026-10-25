#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" u32 func_00295158(u32);
extern "C" u32 func_002941d8(s32);

u16 func_00295270(u32 value, u8 flag) {
    u32 pointer = func_00294000(0) + 16u;
    u32 index = func_00295158(value);
    register u32 offset asm("$15") = index << 4; // why: the original computes the entry offset in t7
    value = pointer + offset;
    if (flag != 0) {
        if (func_002941d8(value) != 0) {
            return *(u16*)(value + 12);
        }
        return *(u16*)(value + 6);
    }
    if (func_002941d8(value) != 0) {
        return *(u16*)(value + 10);
    }
    return *(u16*)(value + 4);
}
