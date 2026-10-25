#include "../common/types.h"
extern "C" s32 D_00350f18;
extern "C" s32 D_00350f1c;
extern "C" s32 D_01d44400;
extern "C" s32 D_01d48c44;
extern "C" u8 D_0036d9a8[];
extern "C" u8 D_01d44440[];
extern "C" u32 func_00102448(...);
extern "C" u32 func_00168388(...);
extern "C" s64 func_001688b8();
extern "C" u32 func_001688c8(...);
extern "C" void func_002fee78(void*, u8*, s32);

s64 func_001b1ee8(s32 task) {
    u8 buffer[48];
    while (D_00350f18 != 0) {
        func_00102448(task, 0);
    }
    D_00350f18 = 1;
    s32 value = *(s32*)(task + 4);
    func_002fee78(buffer, D_0036d9a8, value);
    func_001688c8(buffer);
    func_00168388(buffer, D_01d44440, 0, 0);
    s64 reading;
    while ((reading = func_001688b8()) != 0) {
        func_00102448(task, 0);
    }
    D_00350f1c = value;
    D_00350f18 = 0;
    D_01d44400 = 0;
    D_01d48c44 = 0;
    return reading;
}
