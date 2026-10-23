#include "../common/types.h"
struct Allocator;
typedef s32 (*AllocFn)(Allocator*, u32, s32);
typedef s32 (*FreeFn)(Allocator*, s32);
struct AllocatorTable {
    AllocFn alloc;
    FreeFn free;
};
struct Allocator {
    AllocatorTable* table;
};
extern "C" u8 D_0036ac80[];
extern "C" Allocator* func_001050c8(void);
extern "C" u32 func_001688c8(...);
extern "C" void func_00168388(u8*, s32, s32, s32);
extern "C" s64 func_00170cd0(void);
extern "C" void func_00102448(s32, s32);
extern "C" void func_002bb070(s32, s32, s32, s32, s32);
extern "C" s64 func_002ba200();

s32 func_00136ba8(s32 task) {
    Allocator* allocator = func_001050c8();
    s32 size = func_001688c8(D_0036ac80);
    s32 memory = allocator->table->alloc(allocator, (size + 2111) & ~2047, 0);
    s32 aligned = (memory + 63) & ~63;
    func_00168388(D_0036ac80, aligned, 0, 0);
    while (func_00170cd0() != 0) {
        func_00102448(task, 0);
    }
    func_002bb070(1, aligned, size, 0, 0);
    while (func_002ba200() != 0) {
        func_00102448(task, 0);
    }
    register FreeFn release asm("$15") = allocator->table->free; // why: original calls through t7
    s32 result = release(allocator, memory);
    return result;
}
