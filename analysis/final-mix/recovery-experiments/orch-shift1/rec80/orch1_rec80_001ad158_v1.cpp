#include "../common/types.h"
extern "C" u32 func_001050d8(...);
extern "C" u32 func_001ad0f8(...);

void func_001ad158(int param_1, u32 param_2, u32 param_3, u32 param_4) {
    u32 uVar1;
    int iVar2;

    uVar1 = func_001050d8(0xb6c); asm volatile("" ::: "memory");
    func_001ad0f8(uVar1, param_4, 0); asm volatile("" ::: "memory");
    iVar2 = (int)uVar1;
    *(int *)(param_1 + 0x4a8) = iVar2;
    *(u32 *)(iVar2 + 8) = param_3;
    *(u32 *)(iVar2 + 4) = param_2;
}