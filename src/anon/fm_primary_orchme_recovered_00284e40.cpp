#include "../common/types.h"
struct Allocator;
typedef u32 (*AllocFn)(Allocator*, u32, u32);
struct Allocator {
    AllocFn* vtable;
};
extern "C" u32 D_0035f2c0;
extern "C" u8 D_00374348[];
extern "C" Allocator* func_00103580();
extern "C" void func_002bd730(u8*, u32, u64, u64);
extern "C" void func_002bd788(u32);

void func_00284e40() {
    Allocator* allocator = func_00103580();
    u32 base = allocator->vtable[0](allocator, 0x48800, 0);
    u32 aligned = (base + 63) & ~63;
    D_0035f2c0 = base;
    func_002bd788(aligned);
    func_002bd730(D_00374348, 0x3fff, 0, 0);
}
