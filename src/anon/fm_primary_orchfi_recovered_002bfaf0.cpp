#include "../common/types.h"
extern "C" u32 D_00361a50;
extern "C" u8* D_0034e948;
extern "C" void func_001c11a8(s32);
extern "C" void func_00197780();
extern "C" void func_00197cc0();
extern "C" void func_00139858(u32);

void func_002bfaf0() {
    D_00361a50 = 0;
    func_001c11a8(12);
    u8* pointer = *(u8**)(D_0034e948 + 2880);
    *(u32*)(pointer + 44) &= ~1u;
    func_00197780();
    func_00197cc0();
    func_00139858(201);
}
