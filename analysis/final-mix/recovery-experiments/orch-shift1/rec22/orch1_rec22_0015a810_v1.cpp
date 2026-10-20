#include "../common/types.h"
typedef s32 (*AllocFn)(void*, s32, s32);
struct Allocator {
    AllocFn* vtable;
};
extern "C" s32 D_0034aa90;
extern "C" Allocator* func_001050c8();

void func_0015a810() {
    Allocator* allocator = func_001050c8();
    D_0034aa90 = allocator->vtable[0](allocator, 0x800, 0);
}