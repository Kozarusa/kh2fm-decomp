#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
// why: extern "C" because the isolated probe linker script defines only the plain symbol; the accepted C++ void declaration failed to link in v1
extern "C" void func_00250928();
// why: extern "C" because the isolated probe linker script defines only the plain symbol; the accepted asm-label void declaration failed to link in v1
extern "C" void func_0028ce38();
extern "C" u32* D_0035ee3c;
extern "C" u32* D_0035ee44;
extern "C" u32* D_0035ee40;
extern "C" u32 D_0035ee34;
extern "C" u32 D_0035ee38;

void func_0024fe30() {
    if (func_00139d78(D_0035ee3c) != 0) {
        u32* object = D_0035ee3c;
        ((void (*)(u32*))(*(u32*)(*object + 20)))(object);
    }
    if (func_00139d78(D_0035ee44) != 0) {
        u32* object = D_0035ee44;
        ((void (*)(u32*))(*(u32*)(*object + 20)))(object);
    }
    if (func_00139d78(D_0035ee40) != 0) {
        u32* object = D_0035ee40;
        ((void (*)(u32*))(*(u32*)(*object + 20)))(object);
    }
    if (func_0028acc8(D_0035ee34) != 0) func_0028abe0(D_0035ee34);
    if (func_0028acc8(D_0035ee38) != 0) func_0028abe0(D_0035ee38);
    func_00250928();
    func_0028ce38();
}
