#include "../common/types.h"
extern "C" u32 D_0035db18;
extern "C" u32* D_0035dae4;
extern "C" u32 D_0035dae8;
extern "C" u32 func_00224e90(u32*);
extern "C" u32* func_001050c8();
extern "C" s32 func_001063c0(u32, u32);
extern "C" u32 func_00170b30(...);
// why: this is sa::EVENT_ALLOC::init(void*, s32) from sasa/event_alloc.hpp with its this pointer as the first argument; that member form failed the isolated link in v1 because the probe linker script defines only the plain symbol
extern "C" void func_00225e70(u32* allocator, void* heap, s32 size);

void func_00225550(u32* object) {
    if (func_00224e90(object) != 0) {
        return;
    }
    if (D_0035db18 != 0x400000) {
        return;
    }
    if (D_0035dae4 != 0) {
        return;
    }
    // why: keeps store order (the original stores the three zeros before the global)
    volatile u32* block = (volatile u32*)func_001063c0(12, (u32)func_001050c8());
    block[0] = 0;
    block[1] = 0;
    block[2] = 0;
    // why: keeps store order (the original stores the global after the three zero stores)
    *(volatile u32* volatile*)&D_0035dae4 = block;
    u32 heap = func_00170b30(0x200000);
    D_0035dae8 = heap;
    func_00225e70(D_0035dae4, (void*)heap, 0x200000);
}
