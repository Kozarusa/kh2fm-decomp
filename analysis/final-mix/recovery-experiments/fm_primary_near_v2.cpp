#include "../common/types.h"

extern "C" u32 func_001d17b0(...);
extern "C" u32 func_00195530(void);
extern "C" int func_00195468(s32, s16);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_00170950(...);
extern "C" u32 func_002537c8(s32);
extern "C" u32 func_0023fa08(void*, u32);
extern u32 D_0035f3a8;

void func_001954a0(u32 object, u32 value) {
    s32 result = func_00195530();
    if (result == 0) {
        result = func_00195468(object, 0);
        if (result >= 0)
            *(u16*)((s32)result * 2 + (s32)object + 8) = value;
    }
}

void func_001d2248(s32 object, s32 value) {
    if (*(s32*)(object + 0x38) < value) {
        register s32* saved asm("$16") = (s32*)object;
        asm("" : "+r"(saved));
        saved[14] = value;
        func_001d17b0();
        if (saved[7] != 0 && saved[7] < saved[14])
            saved[7] = saved[14];
    }
}

struct __attribute__((aligned(16))) FmLocalQuad { u32 words[4]; };

void func_001b6dd0(u32 object, const FmLocalQuad* source) {
    FmLocalQuad copy;
    // Retain the original quadword register and stack-local copy instructions.
    asm volatile("lq $8,0(%1); sq $8,0($sp)"
                 : "=m"(copy) : "r"(source) : "$8", "memory");
    func_0017c4c8(object, &copy);
    *(u8*)(object + 0x514) = 3;
}

void func_00290a60(s32 object) {
    func_00170950(*(u32*)(object + 4));
    *(u8*)(object + 0x10) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(object + 4) = 0;
}

void func_00256b40(void) {
    u32 result = func_002537c8(2);
    func_0023fa08(&D_0035f3a8, result);
}
