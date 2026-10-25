#include "../common/types.h"
extern "C" s8 D_0035f5a0;
extern "C" u8* D_0035f598;
extern "C" u32 D_0035f200;
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_002766d0(void);
// why: no recovered declaration; a0 is a sign-extended halfword, v0 is used as a record pointer
extern "C" u8* func_002983d8(s32);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_002891b8(u32, s32);

// why: u32 return; every exit leaves a direct callee v0 (GetMode on the skip path, func_00192048 on the main path), so void is not allowed

u32 func_00298e48() {
    u32 result;
    u32 entry;
    u8* album;
    u32 item;

    result = func_00287bc0();
    if (result == 5) {
        entry = func_002766d0() + 0xd30;
        album = func_002983d8(*(s16*)(D_0035f598 + D_0035f5a0 * 2 + 4));
        *(u32*)(entry + 0x198) = func_00192048(*(u16*)(album + 8));
        item = func_002891b8(D_0035f200, 0);
        result = func_00192048(*(u16*)(album + 10));
        *(u32*)(item + 0x198) = result;
    }
    return result;
}
