#include "../common/types.h"
extern "C" s32 func_001e3650(...);
extern "C" u32 func_001e3660(s32,s32);
extern "C" u32 func_001e3c98(void*,s32);
extern "C" u32 func_001e3e48(void*,s32);
extern "C" u32 func_001e4028(void*,s32);

void func_001e41e0(int param_1) {
    u32 uVar1;
    uVar1 = func_001e3650(*(u32 *)(param_1 + 0x88)); asm volatile("" ::: "memory");
    uVar1 = func_001e3660(uVar1,2); asm volatile("" ::: "memory");
    uVar1 = func_001e3c98((void*)uVar1,*(int *)(param_1 + 0x8c) + 0xc0); asm volatile("" ::: "memory");
    uVar1 = func_001e3e48((void*)uVar1,*(int *)(param_1 + 0x8c) + 0xd0); asm volatile("" ::: "memory");
    func_001e4028((void*)uVar1,*(int *)(param_1 + 0x8c) + 0xe0); asm volatile("" ::: "memory");
}