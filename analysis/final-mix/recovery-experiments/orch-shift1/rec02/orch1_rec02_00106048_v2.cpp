#include "../common/types.h"
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001058e8(void);

void func_00106048() {
    // why: dead local stores in the original are kept by volatile
    volatile u8 a;
    volatile u8 b;
    volatile u8 c;
    volatile u16 d;
    volatile u16 e;
    volatile u16 f;
    u16 fill = 0xffff;
    f = fill;
    a = fill;
    b = fill;
    c = fill;
    d = fill;
    e = fill;
    *(u8*)(func_001058e8() + 0xc) = 0xf;
    a = 0xf;
    *(u8*)(func_001058e8() + 0xd) = 0;
    b = 0;
    *(u8*)(func_001058e8() + 0xe) = 0;
    c = 0;
    u32 object = func_00102c80();
    ((void (*)(u32))(*(u32**)object)[0])(object);
}
