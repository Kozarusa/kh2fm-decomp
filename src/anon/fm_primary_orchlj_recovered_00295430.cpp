#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" u32 func_002941d8(s32);

u16 func_00295430(s32 value, u8 flag) {
    u32 info = func_00294000(0);
    s32 count = *(s32*)(info + 8);
    s32 found = -1;
    s32 index = 0;
    u32 base = info + 16;
    if (count > 0) {
        s8* cursor = (s8*)base;
        do {
            if (*cursor == value) {
                found = index;
                break;
            }
            cursor += 16;
            index++;
        } while (index < count);
    }
    if (flag != 0) {
        u32 entry = base + found * 16;
        if (func_002941d8(entry) != 0) return *(u16*)(entry + 12);
        return *(u16*)(entry + 6);
    }
    u32 entry = base + found * 16;
    if (func_002941d8(entry) != 0) return *(u16*)(entry + 10);
    return *(u16*)(entry + 4);
}
