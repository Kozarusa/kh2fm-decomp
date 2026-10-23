#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" void func_0023d820(u32);
extern "C" void func_00274ac8();
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_00287dc0(void);
extern "C" void func_0028f7e8(s32);
extern "C" void func_0029ac00();
extern "C" u32 func_0029e9d0();
extern "C" s32 D_0035f5bc;

u32 func_0029aac0(s32 kind) {
    s32 mode;
    u32 object;
    mode = func_00287bc0();
    if (1 < mode - 0xeU && mode != 0x12 && mode != 0x15 && mode != 0x10 && mode != 0x13 &&
        mode != 0x16 && mode != 0x11 && mode != 0x14 && mode != 0x17) {
        return mode;
    }
    func_00274ac8();
    if (1 < kind - 0xeU && kind != 0x12 && kind != 0x15 && kind != 0x10 && kind != 0x13 && kind != 0x16) {
        func_0028f7e8(0);
    }
    if (1 < kind - 0xfU && kind != 0x12 && kind != 0x15) {
        func_0028f7e8(1);
    }
    func_0029ac00();
    object = func_00287dc0();
    if (func_00139d78(object) != 0) {
        func_0023d820(object);
    }
    if (func_00139d78(D_0035f5bc) != 0) {
        func_0023d820(D_0035f5bc);
    }
    return func_0029e9d0();
}
