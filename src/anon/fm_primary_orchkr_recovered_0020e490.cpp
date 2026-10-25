#include "../common/types.h"
// Declarations of 002fd348 and 002fe0a0 and this note are copied from the accepted sibling
// fm_primary_queuedelta_recovered_0020e548.cpp, which calls both the same way:
// Original 002fd348 calls thunk 001002a0, which tail-jumps through
// 0030f468 to _Exit at 00305240. The diagnostic failure path does not return.
extern "C" void func_002fd348(u64) __attribute__((noreturn));
extern "C" void func_002fe0a0(s32);
extern "C" void func_002f28b8(void* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
// why: accepted call sites (fm_primary_globalcall_recovered_0020f118.cpp, 0020f150, fm_primary_orchal_recovered_0014d8d0.cpp)
// declare void(u32, u32) because they discard the result; the original 002f25a0 writes v0 on every path (0, -1 or a
// status mask) and this target returns that v0 on its flag path, which a void declaration cannot express
extern "C" u32 func_002f25a0(u32, u32);
extern "C" void func_003058a0(u32);
extern "C" u32 func_002f2be0(...);
extern "C" char D_00370720;

u32 func_0020e490(u8* object, u32 flag) {
    u8 packet[96];
    if (*(s32*)(object + 20) == 0) {
        func_002fe0a0((s32)&D_00370720);
        func_002fd348(1);
    }
    func_002f28b8(packet, (s16)(*(u16*)object & 0x3fff), object[10] >> 2, object[24],
                  object[8] << 4, object[9] << 4, *(s16*)(object + 12), *(s16*)(object + 14));
    func_002f25a0(0, 0);
    func_003058a0(0);
    u32 result = func_002f2be0(packet, *(s32*)(object + 20));
    if (flag != 0) {
        result = func_002f25a0(0, 0);
    }
    return result;
}
