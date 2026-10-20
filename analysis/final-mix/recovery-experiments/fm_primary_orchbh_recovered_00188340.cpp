#include "../common/types.h"
extern "C" s32 func_00188398(void*, u32, s32*, s32);

s32 func_00188340(u8* object, s32 index, s32* pointer, s32 flag) {
    s32 buffer[4];
    s32 table = *(s32*)(object + 0x90);
    s32 result = 0;
    if (table != 0 && (*(s32*)(object + 0x9c) & 4) == 0) {
        if (pointer == 0) {
            buffer[0] = *(s32*)(object + 0x88);
            pointer = buffer;
            flag = 1;
        }
        result = func_00188398(object, *(u16*)(index * 2 + table + 10), pointer, flag);
    }
    return result;
}
