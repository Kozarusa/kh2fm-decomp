#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" void func_002ef028(u8*, f32);
extern "C" u32 func_0011ea40(f32, u32);
extern "C" u32 func_0011c4e8(u32, u32, u32, u32, void*, u32, f32);

s32 func_002eedf0(u8* object) {
    register u8* self asm("$17") = object; // why: original keeps the object pointer in s1
    f32 value = D_00349e10;
    u8* inner = self + 0x1c8;
    func_002ef028(inner, value);
    func_0011ea40(value, *(u32*)(self + 0x44));
    f32 scale = *(f32*)(inner + 0x10);
    u32 count = *(u32*)(inner + 8);
    func_0011c4e8(*(u32*)(self + 0x44), (u32)(self + 0x150), count, 0, 0, 0, scale);
    return 1;
}
