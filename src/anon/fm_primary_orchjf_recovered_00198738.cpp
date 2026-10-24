#include "../common/types.h"
extern "C" s32 func_00168b88(s32,u32,s32,s32);

u32 func_00198738(u8* object, s8* key) {
    u8* table = *(u8**)(object + 0x7b0);
    if (table != 0) {
        u8* entry = (u8*)func_00168b88((s32)table, 0x16, key[0] | (key[2] << 16) | ((key[3] << 24) | (key[1] << 8)), 0);
        if (entry != 0) {
            return *(u32*)(entry + 8);
        }
    }
    return 0;
}
