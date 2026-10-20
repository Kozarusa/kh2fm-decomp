#include "../common/types.h"
struct Pack10 { u8 a; u8 b; u8 c; u16 d; u16 e; u16 f; };
extern "C" u32 func_00104f58(void*,u64,s64,u8,s64);
extern "C" void func_00199718(void*, u64, s64);

void func_00173008(u32* object) {
    Pack10 pack;
    Pack10 temp;
    pack.a = 0xff;
    pack.b = 0xff;
    pack.c = 0xff;
    pack.d = 0xffff;
    pack.e = 0xffff;
    pack.f = 0xffff;
    func_00199718(&temp, object[0], -1);
    pack = temp;
    func_00104f58(&pack, object[1], 0, 0, 0);
}