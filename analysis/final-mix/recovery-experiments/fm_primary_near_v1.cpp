#include "../common/types.h"

extern "C" u32 func_001d17b0(...);
extern "C" u32 func_00195530(void);
extern "C" int func_00195468(s32, s16);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_00170950(...);
extern "C" u32 func_002537c8(s32);
extern "C" u32 func_0023fa08(void*, u32);
extern u32 D_0035f3a8;

// The original carries the full incoming value and truncates only at the store.
void func_001954a0(u32 object, u32 value) {
    s32 result = func_00195530();
    if (result == 0) {
        result = func_00195468(object, 0);
        if (result >= 0)
            *(u16*)((s32)result * 2 + (s32)object + 8) = value;
    }
}

// Preserve the saved object register used by the original store delay slot.
void func_001d2248(s32 object, s32 value) {
    if (*(s32*)(object + 0x38) < value) {
        register s32* saved asm("$16") = (s32*)object;
        asm("" : : "r"(saved));
        saved[14] = value;
        func_001d17b0();
        if (*(s32*)(object + 0x1c) != 0 && *(s32*)(object + 0x1c) < *(s32*)(object + 0x38))
            *(s32*)(object + 0x1c) = *(s32*)(object + 0x38);
    }
}

struct __attribute__((aligned(16))) FmLocalQuad { u32 words[4]; };

// A whole aligned block is passed to the callee, not a lone scalar local.
void func_001b6dd0(u32 object, const FmLocalQuad* source) {
    FmLocalQuad copy = *source;
    func_0017c4c8(object, &copy);
    *(u8*)(object + 0x514) = 3;
}

void func_00290a60(s32 object) {
    func_00170950(*(u32*)(object + 4));
    *(u8*)(object + 0x10) = 0;
    asm volatile("" ::: "memory");
    *(u32*)(object + 4) = 0;
}

// The original materializes a signed-low address split rather than an integer.
void func_00256b40(void) {
    u32 result = func_002537c8(2);
    func_0023fa08(&D_0035f3a8, result);
}
