#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00287bc0(void);
// why: a0 is the list buffer, a1 the constant 232 (declaration from fm_primary_orchlc_recovered_00272340.cpp)
extern "C" u32 func_0028dac8(u32, s32);
extern "C" void func_0027b4e8(void);
extern "C" u32 func_0028be58(u8*);
// why: extern "C" because the accepted asm-label form fails the isolated link in fm_primary_orchlc_recovered_00272340.cpp; the probe linker script defines only the plain symbol
extern "C" u32 func_0028bdb8(u8* object);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028acb8(u32);
extern "C" u32 func_0028aa40(u32);
extern "C" u8* D_0035f04c;
extern "C" u32 D_0035f01c;

u32 func_0027a7e0(u8 flag) {
    u32 object = func_00257770();
    u32 result = func_00287bc0();
    if (result == 16) {
        func_0028dac8(object, 232);
        if (flag) {
            func_0027b4e8();
        }
        if (func_0028be58(D_0035f04c) != 0) {
            func_0028bdb8(D_0035f04c);
        }
        result = func_0028acc8(D_0035f01c);
        if (result) {
            result = func_0028acb8(D_0035f01c);
            if (!result) return func_0028aa40(D_0035f01c);
        }
    }
    return result;
}
