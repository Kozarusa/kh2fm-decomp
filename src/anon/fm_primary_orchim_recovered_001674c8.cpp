#include "../common/types.h"
extern "C" u8 D_0036b568[];
extern "C" u8 D_0036b580[];
extern "C" u8 D_0036b590[];
extern "C" u8 D_0036b5a0[];
extern "C" u8 D_0036b5b0[];
extern "C" u8 D_0036b5c0[];
extern "C" u8 D_0036b5d0[];
extern "C" u8 D_0036b5e0[];
extern "C" u8 D_0036b5f0[];
extern "C" u8 D_004f4250[];
extern "C" void func_00308b30(s32);
extern "C" void func_0030a690();
extern "C" void func_002f74c8(s32);
extern "C" void func_002f7f18(s32);
extern "C" s32 func_0030eca0(u8*);
extern "C" s32 func_0030ec50();
extern "C" void func_002f6870(s32, u8*, s32);
extern "C" u32 func_00167448(u8*);

u32 func_001674c8() {
    func_00308b30(0);
    func_0030a690();
    func_002f74c8(0);
    func_002f7f18(2);
    while (func_0030eca0(D_0036b568) == 0) {
    }
    while (func_0030ec50() == 0) {
    }
    func_00308b30(0);
    func_002f74c8(0);
    func_002f6870(10, D_004f4250, 0x1000);
    func_002f7f18(2);
    func_00167448(D_0036b590);
    func_00167448(D_0036b5a0);
    func_00167448(D_0036b5b0);
    for (s32 index = 0; index < 2; index++) {
        func_00167448(D_0036b580);
    }
    func_00167448(D_0036b5c0);
    func_00167448(D_0036b5d0);
    func_00167448(D_0036b5e0);
    return func_00167448(D_0036b5f0);
}
