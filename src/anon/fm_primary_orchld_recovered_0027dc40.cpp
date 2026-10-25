#include "../common/types.h"
extern "C" u32 func_00103570();
extern "C" u32 func_001063f0(u64, u64);
extern "C" void func_00239700(u32);
// why: the callee reads a0 as the object it builds and its own instructions never write v0
extern "C" void func_003237e0(u8* object);
extern "C" u8* D_00347f80;
extern "C" u8 D_00347e60[];
extern "C" u8* D_0035f244;
extern "C" u8* D_0035f248;
extern "C" u8 D_0035f24c;
extern "C" u8 D_0035f24d;
extern "C" u8 D_0035f24e;

struct Allocator;
// why: the original calls slot 0 of the allocator's first word with the allocator, 408 and 0
typedef u8* (*AllocMethod)(Allocator*, s32, s32);
struct Allocator {
    AllocMethod* table;
};

// why: void per DEVIATIONS #36; the single exit holds v0 left by func_003237e0, whose own instructions never write v0 (stale-b)

void func_0027dc40(void) {
    s32 count = 3;
    Allocator* allocator = *(Allocator**)(D_00347f80 + 20);
    u8* object = allocator->table[0](allocator, 408, 0);
    *(u32*)(object + 12) = 0;
    *(u8**)object = D_00347e60;
    func_00239700((u32)(object + 24));
    D_0035f244 = object;
    // why: the original passes the 32-bit system value unchanged (no zero extension), so it is widened as signed
    u32* block = (u32*)func_001063f0(20468, (s32)func_00103570());
    *block = 4;
    u8* entry = (u8*)(block + 1);
    u8* cursor = entry;
    do {
        count--;
        func_003237e0(cursor);
        cursor += 5116;
    } while (count != -1);
    D_0035f248 = entry;
    D_0035f24c = 255;
    D_0035f24d = 255;
    D_0035f24e = 255;
}
