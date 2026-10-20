#include "../common/types.h"

extern "C" u32 func_00152598(u32, s32, s32, const void*);
extern "C" u32 func_00152508(u32, u32, u32, u32, u32);
extern "C" u32 func_00167e28(void*);
extern "C" s32 func_00185da8(s32);
extern "C" void func_0016c568(f32, s32, u32);
extern "C" u32 func_0016cc18(s64, s64, u64, u64, s64);
extern "C" u32 func_00154ee8(...);
extern "C" u32 func_00138c10(void*, u32);
extern "C" u32 func_00154408(void*, u32);
extern u8 D_0034a6b8, D_0034d6c0, D_0034d720;

void func_00152990(u32 object, u32 unused, u32 third, u32 fourth,
                   u32 fifth, u32 sixth, u32 seventh, u32 eighth) {
    u32 created = func_00152598(object, seventh, fifth, &D_0034a6b8);
    *(s32*)(object + 0x1c0) = seventh;
    *(u32*)(object + 0x1bc) = sixth;
    *(s32*)(object + 0x1b8) = fifth;
    *(s32*)(object + 0x1b4) = third;
    func_00152508(object, created, third, fourth, eighth);
}

void func_00167ee0(void) {
    func_00167e28(&D_0034d6c0);
    func_00167e28(&D_0034d720);
}

// The original clears f12 and passes the iterator and object in a0/a1.
// This signature is a transport proposal, not an established callee prototype.
void func_00185e20(u32 object) {
    s32 iterator = 0;
    while ((iterator = func_00185da8(iterator)) != 0)
        func_0016c568(0.0f, iterator, object);
}

// Preserve the original a0/a1 tests and forwarding to the five-argument call.
u32 func_00188398(s32 object, s64 condition, u64 third, u64 fourth) {
    s64 loaded = *(s32*)(*(s32*)(*(s32*)(object + 0x88) + 4) + 0x484);
    u32 result = 0;
    if (loaded != 0 && condition != 0) {
        func_0016cc18(loaded, condition, third, fourth, 0);
        result = 1;
    }
    return result;
}

void func_00155410(s32 object) {
    u32 value = **(u32**)(*(s32*)(object + 0x34) + 0x48c);
    *(volatile u32*)(object + 0x24) = value;
    *(volatile u32*)(object + 0x28) = value;
    u32 result = func_00154ee8();
    func_00138c10((void*)(object + 0x394), result);
    func_00154408((void*)(object + 0x40), *(u32*)(object + 0x18));
}
