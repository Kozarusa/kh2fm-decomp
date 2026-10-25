#include "../common/types.h"
// Types copied from the accepted definitions in fm_scalar_recovered_08.cpp.
// why: extern "C" because v1 (C++ linkage and asm-label declarations) failed the isolated probe link.
extern "C" void func_002d1270(u64 mode, u64 option);
// why: extern "C" because v1 (C++ linkage) failed the isolated probe link.
extern "C" void func_002dc278(u64 mode, u64 option);
// why: extern "C" because v1 (C++ linkage) failed the isolated probe link.
extern "C" void func_002e0bb0(u64 mode);
// why: extern "C" because v1 (C++ linkage) failed the isolated probe link.
extern "C" void func_002e1f40(u64 mode);
// why: no accepted declaration (registry name Ti::MGHachimitsu::init(int,int)); parameters from a0/a1
// set before the tail jumps; the asm-label form in v1 failed the isolated probe link.
extern "C" void func_002d6f28(s32 a, s32 b);
// why: no accepted declaration; the tail jump sets no argument registers.
extern "C" void func_002bea88();
// why: no accepted declaration; the tail jump sets no argument registers.
extern "C" void func_001cebb0();

void func_001d7218(s32 id) {
    switch (id) {
    case 3:
        func_002d1270(1, 0);
        break;
    case 4:
        func_002d6f28(1, 0);
        break;
    case 5:
        func_002dc278(1, 0);
        break;
    case 12:
        func_002bea88();
        break;
    case 50:
    case 51:
    case 52:
        func_001cebb0();
        break;
    case 58:
        func_002d1270(0, 0);
        break;
    case 59:
        func_002d6f28(0, 0);
        break;
    case 60:
        func_002dc278(0, 0);
        break;
    case 226:
    case 367:
        func_002e0bb0(0);
        break;
    case 255:
        func_002d1270(2, 0);
        break;
    case 256:
        func_002d6f28(2, 0);
        break;
    case 257:
    case 349:
        func_002dc278(2, 0);
        break;
    case 271:
    case 310:
        func_002e1f40(0);
        break;
    }
}
