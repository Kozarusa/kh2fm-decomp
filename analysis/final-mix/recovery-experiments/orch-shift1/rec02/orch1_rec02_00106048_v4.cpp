#include "../common/types.h"
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001058e8(void);

struct Record {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    u16 d;
    u16 e;
    u16 f;
};

void func_00106048() {
    // why: dead local stores in the original are kept by volatile
    volatile Record record;
    u16 fill = 0xffff;
    record.f = fill;
    record.a = fill;
    record.b = fill;
    record.c = fill;
    record.d = fill;
    record.e = fill;
    *(u8*)(func_001058e8() + 0xc) = 0xf;
    record.a = 0xf;
    *(u8*)(func_001058e8() + 0xd) = 0;
    record.b = 0;
    *(u8*)(func_001058e8() + 0xe) = 0;
    record.c = 0;
    u32 object = func_00102c80();
    ((void (*)(u32))(*(u32**)object)[0])(object);
}
