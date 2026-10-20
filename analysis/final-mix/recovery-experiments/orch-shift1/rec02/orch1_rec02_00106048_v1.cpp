#include "../common/types.h"
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001058e8(void);

void func_00106048() {
    // why: dead local stores in the original are kept by volatile
    volatile u8 a = 0xff;
    volatile u8 b = 0xff;
    volatile u8 c = 0xff;
    volatile u16 d = 0xffff;
    volatile u16 e = 0xffff;
    volatile u16 f = 0xffff;
    *(u8*)(func_001058e8() + 0xc) = 0xf;
    a = 0xf;
    *(u8*)(func_001058e8() + 0xd) = 0;
    b = 0;
    *(u8*)(func_001058e8() + 0xe) = 0;
    c = 0;
    u32 object = func_00102c80();
    ((void (*)(u32))(*(u32**)object)[0])(object);
}
