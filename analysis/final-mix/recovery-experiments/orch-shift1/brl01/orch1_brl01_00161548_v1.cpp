#include "../common/types.h"
extern "C" u32 func_00168b38(void*, u32, s32);

u32 func_00161548(u8* object, s32 index) {
    u32 result;
    if (index < 0) {
        result = 0;
    } else if (*(void**)(object + 0x40) == 0) {
        result = 0;
    } else {
        u32* item = (u32*)func_00168b38(*(void**)(object + 0x40), 9, index);
        if (item == 0) {
            result = 0;
        } else {
            result = item[2];
        }
    }
    return result;
}
