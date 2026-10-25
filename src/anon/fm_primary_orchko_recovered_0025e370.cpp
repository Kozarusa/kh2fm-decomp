#include "../common/types.h"
extern "C" u8 D_00373110[];
extern "C" s32 func_00287cd0();
// why: extern "C" because v1 (C++ linkage, as in the recovered definition) failed the isolated probe link, whose linker script defines only the plain symbol
extern "C" u32 func_002b4fb8();
// why: derived from registers (no recovered call site); 00287c10 returns a value compared with 1
extern "C" s32 func_00287c10();
// why: derived from registers (no recovered call site); a0 = 0 before the call
extern "C" void func_00233e70(s32);
// why: derived from registers (no recovered call site); 00233e60 ends with sltiu v0 (returns a flag)
extern "C" s32 func_00233e60();
extern "C" s32 func_00287c30();
// why: derived from registers (no recovered call site); a0 = 0 before the call
extern "C" void func_00287d20(s32);
extern "C" u32 func_00287bc0(void);
// why: derived from registers (no recovered call site); a0 = D_00373110, a1 = 1; its last call writes no v0
extern "C" void func_002b5188(u8*, s32);
extern "C" u32 func_00287cc0(...);
// why: derived from registers (only a placeholder file defines it); a0 = 8000 before the call
extern "C" void func_00240bb0(s32);
// why: extern "C" because v1 (C++ linkage, as in the recovered definition) failed the isolated probe link, whose linker script defines only the plain symbol
extern "C" void func_002417a0(void);
// why: derived from registers (no recovered call site); no arguments are set before the call
extern "C" void func_002b4ee0();
extern "C" s32 func_00287c00(s32);

void func_0025e370() {
    s32 state = func_00287cd0();
    if (state == 2) {
        if (func_002b4fb8() == 0) {
            if (func_00287c10() == 1) {
                func_00233e70(0);
                if (func_00233e60() == 0) {
                    return;
                }
            }
            func_00287c30();
            func_00287d20(0);
            if (func_00287bc0() == 12) {
                func_002b5188(D_00373110, 1);
            }
        }
    } else {
        if (state == 0) {
            func_00287cc0(1);
        }
        func_00240bb0(8000);
        func_002417a0();
        func_002b4ee0();
        func_00287c00(12);
        func_00287cc0(2);
    }
}
