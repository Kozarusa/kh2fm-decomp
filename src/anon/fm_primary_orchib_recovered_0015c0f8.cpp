#include "../common/types.h"
struct Allocator;
typedef u8* (*AllocateFn)(Allocator*, s32, s32);
struct Allocator { AllocateFn* table; };
extern "C" u8* D_00347f80;
extern "C" u8 D_0034af08[];
extern "C" u8* D_0034ae80;
extern "C" s32 D_0034ece0;
extern "C" void func_0031daf0(u8*);
extern "C" s32 func_001492e8(u8*, s32);
extern "C" s32 func_0015bbc8(u8*, u32);

// Preserve original registry aliases.
void func_0015c0f8(u8* owner) asm("_Z17ctarget0_0015c0f8v");

void func_0015c0f8(u8* owner) {
    Allocator* allocator = *(Allocator**)(D_00347f80 + 20);
    u8* object = allocator->table[0](allocator, 3040, 0);
    s32 result;
    *(s32*)(object + 12) = 0;
    *(u8**)(object + 0) = D_0034af08;
    func_0031daf0(object + 48);
    D_0034ae80 = object;
    if (D_0034ece0 == 99) return;
    result = func_001492e8(owner, D_0034ece0);
    if (result == 0) return;
    func_0015bbc8(D_0034ae80, result);
}
