#include "../common/types.h"
extern "C" s32 func_00168b88(s32, u32, s32, s32);

u32 func_00198738(s32 object, s8* key) {
    s32 table = *(s32*)(object + 0x7b0);
    if (table == 0) {
        return 0;
    }
    s32 entry = func_00168b88(table, 0x16, key[0] | (key[3] << 24) | ((key[2] << 16) | (key[1] << 8)), 0);
    return entry != 0 ? *(u32*)(entry + 8) : 0;
}