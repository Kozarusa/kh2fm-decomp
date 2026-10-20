#include "../common/types.h"
extern "C" s32 func_00168b88(s32, u32, s32, s32);

u32 func_00198738(s32 object, s8* key) {
    if (*(s32*)(object + 0x7b0) == 0) {
        return 0;
    }
    s32 entry = func_00168b88(*(s32*)(object + 0x7b0), 0x16,
                              key[0] | (key[3] << 24) | ((key[2] << 16) | (key[1] << 8)), 0);
    if (entry == 0) {
        return 0;
    }
    return *(u32*)(entry + 8);
}