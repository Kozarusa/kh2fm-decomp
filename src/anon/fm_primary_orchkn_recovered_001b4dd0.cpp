#include "../common/types.h"
extern "C" f32 D_0036da88;
extern "C" u32 D_01d48cb0;
extern "C" u8 D_00351eb8[];
extern "C" u8 D_00352560[];
extern "C" u8 D_00350e48[];
extern "C" bool func_0019ba60(...);
extern "C" u32 func_0016cab8(u32);
extern "C" u32 func_0016c7d8(u32);
extern "C" u32 func_001dde40(void*);
extern "C" void func_001b1c10(u32, f32);
extern "C" u32 func_0016c640(u64);
extern "C" void func_001d4570(u8*, u32);
extern "C" u32 func_00170950(...);
extern "C" s32 func_001b5858(u8*);
extern "C" s32 func_001b5cb8(u8*);
extern "C" u32 func_001c8d98(void*, u32);
extern "C" void func_001d1ed0(u32*);
extern "C" void func_001d2048(u8*);
extern "C" void func_001b0188(u32*);
extern "C" void func_001ddd88(u32);

void func_001b4dd0(u8* object) {
    *(u32*)(*(u8**)(object + 0x0c) + 0x10c) &= 0xfffeffff;
    s32 count = 1;
    u8* cursor = object;
    do {
        if (func_0019ba60(*(u32*)(cursor + 0x10)) != 0) {
            *(u32*)(*(u32*)(cursor + 0x10) + 0x10c) &= 0xfffeffff;
            *(u8*)(*(u32*)(cursor + 0x10) + 0xb4c) = 0;
        }
        count--;
        cursor += 4;
    } while (count >= 0);
    u32 lock = *(u32*)(object + 0x34);
    if (lock != 0) {
        func_0016cab8(lock);
        func_0016c7d8(lock);
    }
    if (*(u32*)(object + 0x18) != 0) {
        func_001dde40(object + 0x18);
    }
    register u8* sub asm("$16") = object + 0x68; // why: original keeps the member at +0x68 in s0 (the loop cursor's register)
    asm("" : "+r"(sub)); // why: keeps the member field read as 0x38(s0) instead of folding it to 0xa0(s1)
    f32* scale = &D_0036da88;
    asm("" : "+r"(scale)); // why: original forms the full address before the load
    func_001b1c10(*(u32*)(object + 0x38), *scale);
    func_0016c640(1);
    func_001d4570(*(u8**)(object + 0x00), *(u32*)(sub + 0x38));
    if (*(u32*)(object + 0x04) != 0) {
        func_00170950(*(u32*)(object + 0x04));
    }
    D_01d48cb0 = 0;
    if (func_001b5858(object) == 0 && func_001b5cb8(object) == 0) {
        func_001c8d98(D_00351eb8, 0);
    }
    *(u8**)(object + 0xa8) = D_00352560;
    func_001d1ed0((u32*)(object + 0xa8));
    func_001d2048(sub);
    *(u8**)(object + 0x48) = D_00350e48;
    func_001b0188((u32*)(object + 0x48));
    func_001ddd88((u32)(object + 0x18));
    asm volatile("" ::: "memory"); // why: original does not tail-call the final member destructor
}
