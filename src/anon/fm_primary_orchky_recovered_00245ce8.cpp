#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" void func_0023d820(u32);
extern "C" u32 func_00287dc0(void);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" void func_00247bb0();
// why: no recovered source calls this function; its result is not used here, so it is declared from the registers (no arguments set)
extern "C" void func_00246f80();
extern "C" u8* D_0035ed28;
extern "C" u8* D_0035ed30;
extern "C" u8* D_0035ed2c;
extern "C" u32 D_0035ed20;
extern "C" u32 D_0035ed24;

void func_00245ce8() {
    if (func_00139d78(D_0035ed28)) {
        u8* object = D_0035ed28;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_00139d78(D_0035ed30)) {
        u8* object = D_0035ed30;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_00139d78(D_0035ed2c)) {
        u8* object = D_0035ed2c;
        ((void (*)(u8*))(*(u32*)(*(u32*)object + 20)))(object);
    }
    if (func_0028acc8(D_0035ed20)) {
        func_0028abe0(D_0035ed20);
    }
    if (func_0028acc8(D_0035ed24)) {
        func_0028abe0(D_0035ed24);
    }
    func_00246f80();
    func_0023d820(func_00287dc0());
    func_00247bb0();
}
