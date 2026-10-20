#include "../common/types.h"
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001058e8(void);
extern "C" u8 func_00105f98(void);

struct Entry {
    u8 a;
    u8 b;
    u8 c;
    u16 d;
    u16 e;
    u16 f;
};

void func_00105fc8() {
    Entry entry;
    u32 mask = 0xffff;
    entry.f = mask;
    entry.a = mask;
    entry.b = mask;
    entry.c = mask;
    entry.d = mask;
    entry.e = mask;
    *(u8*)(func_001058e8() + 0xc) = 15;
    entry.a = 15;
    *(u8*)(func_001058e8() + 0xd) = 0;
    entry.b = 0;
    u32 save = func_001058e8();
    u8 result = func_00105f98();
    *(u8*)(save + 0xe) = result;
    entry.c = result;
    u32 object = func_00102c80();
    (**(void (**)(u32))*(u32*)object)(object);
}

