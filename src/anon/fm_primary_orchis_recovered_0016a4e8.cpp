#include "../common/types.h"
extern "C" u8 D_0034d850[];
extern "C" u32 func_00105110(u64);
extern "C" u32 func_001a17c8(s32);
extern "C" void func_001b78b8(s32);
extern "C" void func_002cb708(u32);
extern "C" void func_001b3098(int*);
extern "C" u32 func_001a9350(...);
extern "C" void func_001a6d68(u8*);
extern "C" u32 func_00187b90(u64);
extern "C" void func_0017eb98(u64);
extern "C" void func_001ddd88(u32);

u32 func_0016a4e8(u8* object) {
    *(u8**)object = D_0034d850;
    s32 value = *(s32*)(object + 1164);
    if (value) func_001a17c8(value);
    s32 second = *(s32*)(object + 2088);
    if (second) func_001b78b8(second);
    s32 third = *(s32*)(object + 1296);
    if (third) func_001b78b8(third);
    s32 pointer = *(s32*)(object + 1288);
    if (pointer) {
        func_002cb708(pointer);
        func_00105110(pointer);
    }
    func_001b3098((int*)(object + 2048));
    func_001a9350(object + 1952);
    func_001a6d68(object + 1280);
    func_00187b90((s32)(object + 768));
    func_0017eb98((s32)(object + 320));
    func_001ddd88((u32)(object + 156));
    func_001ddd88((u32)(object + 128));
    return func_00105110((s32)object);
}
