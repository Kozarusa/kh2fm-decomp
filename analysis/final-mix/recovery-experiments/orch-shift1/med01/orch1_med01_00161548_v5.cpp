#include "../common/types.h"
extern "C" u32 func_00168b38(void*, u32, s32);

u32 func_00161548(u8* object, s32 index) {
    if (index < 0) {
        return 0;
    }
    u32 list = *(u32*)(object + 0x40);
    if (list == 0) {
        return 0;
    }
    u32* item = (u32*)func_00168b38((void*)list, 9, index);
    u32 result = 0;
    if (item != 0) {
        result = item[2];
    }
    return result;
}
