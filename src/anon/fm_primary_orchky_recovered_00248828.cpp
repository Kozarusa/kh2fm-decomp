#include "../common/types.h"
extern "C" u32 D_0035ed4c;
extern "C" u32 D_0035ed50;
extern "C" u32 D_0035ed54;
extern "C" u32 D_0035ed58;
extern "C" u32 D_0035ed5c;
extern "C" s32 func_00139d78(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
// why: extern "C" because the isolated probe linker script defines only the plain symbol (v1 C++ declaration failed the probe link)
extern "C" u32 func_00249358();
// why: extern "C" because the isolated probe linker script defines only the plain symbol (v1 asm-label declaration failed the probe link)
extern "C" void func_0028ce38();

typedef void (*Method)(u32);

void func_00248828() {
    if (func_00139d78(D_0035ed54) != 0) {
        u32 object = D_0035ed54;
        (*(Method*)(*(u32*)object + 20))(object);
    }
    if (func_00139d78(D_0035ed5c) != 0) {
        u32 object = D_0035ed5c;
        (*(Method*)(*(u32*)object + 20))(object);
    }
    if (func_00139d78(D_0035ed58) != 0) {
        u32 object = D_0035ed58;
        (*(Method*)(*(u32*)object + 20))(object);
    }
    if (func_0028acc8(D_0035ed4c)) {
        func_0028abe0(D_0035ed4c);
    }
    if (func_0028acc8(D_0035ed50)) {
        func_0028abe0(D_0035ed50);
    }
    func_00249358();
    func_0028ce38();
}
