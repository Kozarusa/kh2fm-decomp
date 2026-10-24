#include "../common/types.h"
extern "C" s32 D_00350c88;
extern "C" u8 D_00350ca0[];
extern "C" u8 D_00350ca8[];
extern "C" u8* func_001ae460(u32);
extern "C" s32 func_001ae010(u32);
extern "C" void func_001ae620(void);
extern "C" void func_001ae650(void);
extern "C" u64 func_001ae678(...);
extern "C" u64 func_002f79c8(...);
extern "C" s32 func_002f7be8(s32, u32, u32, u8*);
extern "C" s32 func_002f7dc8(void);

s32 func_001ae0a0(u32 name, u32 data, s32 offset, u16 size) {
    u8* entry = func_001ae460(name);
    if (entry == 0) {
        return 0;
    }
    u8* mode;
    if (func_001ae010(name) != 0) {
        mode = D_00350ca8;
    } else {
        mode = D_00350ca0;
    }
    while (1) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*(s32*)(entry + 8) + offset, size, data, mode) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        s32 result = func_002f7dc8();
        D_00350c88 = result;
        if (result == 0) {
            return size << 11;
        }
        func_001ae650();
    }
}
