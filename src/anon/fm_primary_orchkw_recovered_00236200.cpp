#include "../common/types.h"
extern "C" u64 D_0035e3c0[];
extern "C" u64 D_0035e3f0[];
extern "C" void func_003058a0(u32);

// Preserve original registry aliases.
void func_00236200() asm("_Z16u_call0_00236200v");

void func_00236200() {
    D_0035e3c0[0] = 0x70000002;
    D_0035e3c0[2] = 0x1000000000008001ULL;
    D_0035e3c0[3] = 0xe;
    D_0035e3c0[4] = 0x30000;
    D_0035e3c0[5] = 0x47;
    D_0035e3f0[0] = 0x70000004;
    D_0035e3f0[2] = 0x3000000000008001ULL;
    D_0035e3f0[3] = 0xeee;
    D_0035e3f0[4] = 5;
    D_0035e3f0[5] = 8;
    D_0035e3f0[6] = 0x60;
    D_0035e3f0[7] = 0x14;
    D_0035e3f0[8] = 0x44;
    D_0035e3f0[9] = 0x42;
    func_003058a0(0);
}
