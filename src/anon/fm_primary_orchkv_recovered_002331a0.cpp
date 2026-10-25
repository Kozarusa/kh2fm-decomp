#include "../common/types.h"
// why: return type from the accepted definition fm_primary_orchdq_recovered_00227a28.cpp; extern "C" because the isolated probe linker script defines only the plain symbol (C++ form failed to link in lg376 0022d440 v1)
extern "C" u8* func_00227a28();
// why: types from the accepted definition fm_primary_orchdt_recovered_0022f4f0.cpp; extern "C" for the same isolated-link reason as func_00227a28
extern "C" u8* func_0022f4f0(s32 value);
// why: copied from the recovered call site in fm_primary_orchax_recovered_00168958.cpp
extern "C" u32 func_002ff2e8(...);
// why: no accepted source calls it; parameters from a0 (name) and a1 (0022f4f0 result), result used as the next call argument
extern "C" u32 func_002330c8(u8*, u8*);
// why: copied from the recovered call site in fm_primary_oneword_recovered_00232510.cpp, which uses the result
extern "C" u32 func_00227870(...);
// why: copied from the recovered call site in fm_primary_orchiy_recovered_00181ad0.cpp; its result is not used here because it is stale (left by accepted-void func_00168958)
extern "C" s32 func_001684c0(u8*, u8*, s32, s32);
extern "C" u8 D_002330b0[];

void func_002331a0(u8* name, u32 mode, s32 id, s32 value, s32 flag) {
    u8* entry = func_00227a28();
    *(s32*)(entry + 12) = value;
    *(s32*)(entry + 4) = 1;
    *(s32*)(entry + 0) = 1;
    entry[8] = flag != 0;
    *(s32*)(entry + 16) = id;
    func_002ff2e8(entry + 32, func_0022f4f0(id));
    func_002ff2e8(entry + 48, name);
    u32 handle = func_002330c8(name, func_0022f4f0(id));
    u32 buffer = func_00227870(handle, entry, mode);
    *(u32*)(entry + 20) = buffer;
    func_001684c0((u8*)handle, (u8*)buffer, (s32)D_002330b0, (s32)entry);
}
