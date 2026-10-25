#include "../common/types.h"
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f0ec;
extern "C" u32 func_00287bc0(void);
// why: types copied from the definition in fm_primary_orchjj_recovered_0028b160.cpp; extern "C" because probe v1 with the C++ declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" s32 func_0028b160(u8* object, s32 value);
extern "C" u32 func_0028b038(u32);
// why: no recovered call site or definition types this callee; derived from its instructions (returns a0 + 1540)
extern "C" u8* func_00281f30(u32);
// why: no recovered call site or definition types this callee; arguments derived from a0..t0 set before the jal, result unused here
extern "C" void func_001a98e8(u8*, s32, u8*, u32, s32);
extern "C" u32 func_0023aa18(...);
extern "C" u32 func_0023aa38(...);
extern "C" u32 func_0023a918(s32);
// why: no recovered call site or definition types this callee; arguments derived from a0..a3 set before the jal, result unused here
extern "C" void func_001a9ae8(u8*, s32, s32, u32);

// why: object arrives in t0, so two unused word parameters occupy a2 and a3

void func_0026a9f8(s32 x, s32 y, s32 unused2, s32 unused3, u8* object) {
    u8 buffer[96];
    u32 mode = func_00287bc0();
    s32 index = func_0028b160((u8*)D_0035f01c, (s32)object);
    u32 top = func_0028b038(D_0035f01c);
    u8* table = func_00281f30(D_0035f0ec);
    if (mode - 5 >= 2 && top == 0) {
        if (index == 0) return;
        index--;
    }
    func_001a98e8(buffer, 1, table + index * 80, *(u32*)(object + 424), 1);
    s32 px = func_0023aa18(object + 24) + x;
    s32 py = func_0023aa38(object + 24) + y;
    func_001a9ae8(buffer, px, py, func_0023a918((s32)(object + 24)));
}
