#include "../common/types.h"
extern "C" u32 D_0035f01c;
extern "C" u8 D_00373af8[];
extern "C" u32 func_00287bc0(void);       // copied from fm_primary_orchko_recovered_0026a9f8.cpp
// why: types copied from fm_primary_orchko_recovered_0026a9f8.cpp; extern "C" because the probe linker script defines only the plain symbol
extern "C" s32 func_0028b160(u8* object, s32 value);
extern "C" u32 func_00192048(u64);        // copied from fm_primary_dependencyfamily_recovered_00272a70.cpp
extern "C" void func_001a98e8(u8*, s32, u8*, u32, s32); // copied from fm_primary_orchko_recovered_0026a9f8.cpp
extern "C" u32 func_0023aa98(...);        // copied from fm_primary_orchhm_recovered_00152820.cpp
extern "C" u32 func_0023a918(s32);        // copied from fm_primary_orchko_recovered_0026a9f8.cpp
extern "C" void func_001a9ae8(u8*, s32, s32, u32); // copied from fm_primary_orchko_recovered_0026a9f8.cpp

// why: object arrives in t0, so two unused word parameters occupy a2 and a3

void func_00273078(s32 x, s32 y, s32 unused2, s32 unused3, u8* object) {
    u8 buffer[96];
    if (func_00287bc0() != 31) return;
    s32 index = func_0028b160((u8*)D_0035f01c, (s32)object);
    u32 attribute = *(u32*)(object + 424);
    u32 text = func_00192048(*(u16*)(D_00373af8 + (index / 2) * 8));
    func_001a98e8(buffer, 1, (u8*)text, attribute, 0);
    s32 px = x + func_0023aa98(object + 24);
    func_001a9ae8(buffer, px, y, func_0023a918((s32)(object + 24)));
}
