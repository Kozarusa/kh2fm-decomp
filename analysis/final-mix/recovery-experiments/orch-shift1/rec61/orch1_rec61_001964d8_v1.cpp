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
    t.a = 0xff;
    t.b = 0xff;
    t.c = 0xff;
    t.d = 0xffff;
    t.e = 0xffff;
    t.f = 0xffff;
    t = func_00196328(value);
    func_001967f0(t.a, t.b, 1);
}
