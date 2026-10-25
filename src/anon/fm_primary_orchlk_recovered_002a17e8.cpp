#include "../common/types.h"
extern "C" u8* D_0035f5d8;
extern "C" u8* D_0035f5d4;
extern "C" u32 func_00139d78(s32);
extern "C" u32 func_00192048(u32);
// why: parameters copied from the accepted definition fm_primary_orchjl_recovered_00192e50.cpp; extern "C" because the probe linker script defines only the plain symbol
extern "C" u8* func_00192e50(u8* text, u8* out, s32 unused, ...);
// why: argument types from the accepted call site in 00271828; v0 is returned on this path
extern "C" u32 func_002595e8(u32, u32);
// why: parameters copied from the accepted definition fm_primary_orchlj_recovered_00295430.cpp; extern "C" because the probe linker script defines only the plain symbol
extern "C" u16 func_00295430(s32 value, u8 flag);
// why: a0 is a halfword id loaded with lhu, v0 is a record pointer
extern "C" u8* func_002a1bc0(u32);

u32 func_002a17e8() {
    u32 result = func_00139d78((s32)(D_0035f5d8 + 1224));
    s8 slot = D_0035f5d4[1];
    if (slot < 0) {
        *(u32*)(D_0035f5d8 + 1632) = 0;
        return result;
    }
    u8* record = func_002a1bc0(*(u16*)(D_0035f5d4 + slot * 8 + 80));
    if ((*(u16*)(record + 16) & 0x400) != 0) {
        u32 text = func_00192048(*(u16*)(record + 6));
        u32 name = func_00192048(func_00295430(*(s8*)(D_0035f5d4 + 2), 1));
        result = (u32)func_00192e50((u8*)text, D_0035f5d4 + 4, 64, name);
    } else {
        result = func_002595e8((u32)(D_0035f5d4 + 4), func_00192048(*(u16*)(record + 6)));
    }
    *(u32*)(D_0035f5d8 + 1632) = (u32)(D_0035f5d4 + 4);
    return result;
}
