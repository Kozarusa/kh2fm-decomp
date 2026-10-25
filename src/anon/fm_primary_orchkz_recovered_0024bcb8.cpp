#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
// why: the accepted C++ form void func_0024c828() fails the isolated link (v2: unresolved reference to the mangled name), because the isolated probe linker script defines only the plain func_0024c828 symbol
extern "C" void func_0024c828();
// why: the accepted asm-label form of the void definition fails the isolated link (v3: unresolved reference to the label), because the isolated probe linker script defines only the plain func_0028ce38 symbol
extern "C" void func_0028ce38();
extern "C" u8* D_0035edb0;
extern "C" u8* D_0035edb4;
extern "C" u8* D_0035edb8;
extern "C" u32 D_0035eda8;
extern "C" u32 D_0035edac;

void func_0024bcb8(void) {
    if (func_00139d78(D_0035edb0)) {
        u8* object = D_0035edb0;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_00139d78(D_0035edb8)) {
        u8* object = D_0035edb8;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_00139d78(D_0035edb4)) {
        u8* object = D_0035edb4;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_0028acc8(D_0035eda8) != 0) {
        func_0028abe0(D_0035eda8);
    }
    if (func_0028acc8(D_0035edac) != 0) {
        func_0028abe0(D_0035edac);
    }
    func_0024c828();
    func_0028ce38();
}
