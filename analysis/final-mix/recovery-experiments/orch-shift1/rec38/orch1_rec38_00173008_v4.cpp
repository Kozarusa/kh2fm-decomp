#include "../common/types.h"
struct Pack10 { u8 a; u8 b; u8 c; u16 d; u16 e; u16 f; };
extern "C" s32 func_00104f58(void*,s64,s64,u8,s64);
extern "C" void func_00199718(void*, s64, s64);

void func_00173008(s32* object) {
    Pack10 pack;
    Pack10 temp;
    u16 fill = 0xffff;
    pack.a = fill;
    pack.b = fill;
    pack.c = fill;
    pack.d = fill;
    pack.e = fill;
    pack.f = fill;
    func_00199718(&temp, object[0], -1);
    pack = temp;
    func_00104f58(&pack, object[1], 0, 0, 0);
}