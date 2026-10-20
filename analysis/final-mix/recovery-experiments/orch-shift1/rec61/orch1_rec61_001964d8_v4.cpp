#include "../common/types.h"
struct Triple {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    u16 d;
    u16 e;
    u16 f;
};
extern "C" Triple func_00196328(u32);
extern "C" void func_001967f0(u8, u8, u32);

void func_001964d8(u32 value) {
    Triple t;
    u32 mask = 0xffff;
    t.a = mask;
    t.b = mask;
    t.c = mask;
    t.d = mask;
    t.e = mask;
    t.f = mask;
    t = func_00196328(value);
    func_001967f0(t.a, t.b, 1);
}


