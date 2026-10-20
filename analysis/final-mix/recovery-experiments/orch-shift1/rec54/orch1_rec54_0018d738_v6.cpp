#include "../common/types.h"
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" void func_001bff88();
extern "C" void func_001c2b70();
extern "C" volatile s32 D_01c60cd8;
extern "C" u8 D_01c60ce0;
extern "C" void D_0018d620();

void func_0018d738() {
    func_001bff88();
    func_001c2b70();
    // why: volatile keeps the store order and the pointer setup before it
    volatile s32* pointer = &D_01c60cd8;
    D_01c60cd8 = 0;
    pointer[1] = 0;
    func_00102c18(1, 21000, (u64)D_0018d620);
    D_01c60ce0 = 1;
}
