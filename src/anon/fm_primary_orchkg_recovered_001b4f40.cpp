#include "../common/types.h"
extern "C" f32 D_0036da8c;
extern "C" u32 D_01d48cb0;
extern "C" u8 D_00351eb8[];
extern "C" u8 D_00352560[];
extern "C" u8 D_00350e48[];
extern "C" bool func_0019ba60(u64);
extern "C" u32 func_0016cab8(u32);
extern "C" u32 func_0016c7d8(u32);
extern "C" u32 func_001dde40(void*);
extern "C" void func_001b1c10(u32,f32);
extern "C" u32 func_0016c640(u64);
// why: extern "C" because the accepted C++ definition's mangled name does not resolve in the isolated probe link
extern "C" void func_001d4570(u8*, u32);
extern "C" void func_00170950(s32);
extern "C" s32 func_001b5858(u8*);
extern "C" s32 func_001b5cb8(u8*);
extern "C" u32 func_001c8d98(void*,u32);
extern "C" void func_001d1ed0(u32*);
extern "C" void func_001d2048(u8*);
extern "C" void func_001b0188(u32*);
extern "C" void func_001ddd88(u32);

void func_001b4f40(u8* object) {
    u8* owner = *(u8**)(object + 12);
    *(u32*)(owner + 268) &= 0xfffeffff;
    for (s32 index = 0; index < 2; index++) {
        if (func_0019ba60(*(s32*)(object + 16 + index * 4))) {
            *(u32*)(*(u32*)(object + 16 + index * 4) + 268) &= 0xfffeffff;
            *(u8*)(*(u32*)(object + 16 + index * 4) + 2892) = 0;
        }
    }
    u32 handle = *(u32*)(object + 52);
    if (handle != 0) {
        func_0016cab8(handle);
        func_0016c7d8(handle);
    }
    u8* list = object + 24;
    if (*(s32*)list != 0) {
        func_001dde40(list);
    }
    u8* part = object + 104;
    f32* scale = &D_0036da8c;
    asm("" : "+r"(scale)); // why: original forms the full address (lui+addiu) and loads with lwc1 0(reg)
    func_001b1c10(*(u32*)(object + 56), *scale);
    func_0016c640(1);
    func_001d4570(*(u8**)object, *(u32*)(part + 56));
    if (*(s32*)(object + 4) != 0) {
        func_00170950(*(s32*)(object + 4));
    }
    D_01d48cb0 = 0;
    if (func_001b5858(object) == 0 && func_001b5cb8(object) == 0) {
        func_001c8d98(D_00351eb8, 0);
    }
    *(u8**)(object + 168) = D_00352560;
    func_001d1ed0((u32*)(object + 168));
    func_001d2048(part);
    *(u8**)(object + 72) = D_00350e48;
    func_001b0188((u32*)(object + 72));
    func_001ddd88((u32)list);
    asm volatile(""); // why: original calls func_001ddd88 with jal and returns itself (no sibling call)
}
