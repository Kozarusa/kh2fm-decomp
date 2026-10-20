#include "../common/types.h"
extern "C" u32 func_00168b38(void*, u32, s32);

u32 func_00161548(u8* object, s32 index) {
    if (index < 0) {
        return 0;
    }
    void* list = *(void**)(object + 0x40);
    while (list != 0) {
        u32* item = (u32*)func_00168b38(list, 9, index);
        return item != 0 ? item[2] : 0;
    }
    return 0;
}
