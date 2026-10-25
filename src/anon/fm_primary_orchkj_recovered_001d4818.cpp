#include "../common/types.h"
// why: the original copies each word with lwl/lwr and swl/swr, so the element is an unaligned word (pattern of accepted fm_memory_recovered.cpp PackedWord)
struct __attribute__((packed)) PackedWord { u32 value; };
extern "C" PackedWord D_01d5ba58[];
extern "C" PackedWord D_0036e4d0[];
// why: no accepted source declares it; parameters derived from registers (a0, a1), void because it ends with a tail call into store-only func_0013b2d8
extern "C" void func_0013d550(s32, s32);

// why: void per DEVIATIONS #36; the single exit follows the call to func_0013d550, which tail-calls store-only func_0013b2d8 (no v0/$f0 write) after its own v0 crossed later calls: stale-b

void func_001d4818(s32* object, s32 mode, s32 first, s32 second, s32 extra) {
    object[0] = mode;
    func_0013d550(first, second);
    object[1] = extra;
    if (mode == 3) {
        for (u32 index = 0; index < 3; index++) {
            D_01d5ba58[index] = D_0036e4d0[index];
        }
    }
}
