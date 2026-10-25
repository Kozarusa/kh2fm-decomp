#include "../common/types.h"
extern "C" u8* D_01d49978;
extern "C" u8 D_00321058[];
extern "C" u8* func_002fd248(u32, u8*, u32, u32, u8*);
extern "C" void func_0015ee90(s32);
extern "C" void func_0015ee10(s32);

// why: void per ruling #36: exits after a loop call leave v0 stale through void func_0015ee90/func_0015ee10 (stale-b); the no-call exit leaves the consumed func_002fd248 lookup pointer (direct)

void func_001c8ec0(u32 value) {
    u8* entry = func_002fd248(value, D_01d49978 + 8, *(u32*)(D_01d49978 + 4), 24, D_00321058);
    s32 index;
    for (index = 0; index < 64; index++) {
        if ((*(u64*)(entry + 8) >> index) & 1) {
            func_0015ee90(index);
        } else if ((*(u64*)(entry + 16) >> index) & 1) {
            func_0015ee10(index);
        }
    }
}
