#include "../common/types.h"
extern "C" u8 D_01d49520[];
extern "C" u8 D_00351408[];
// why: parameters derived from registers: the original sets mtc1 zero,$f12 before jal func_001980d0, which passes f12 untouched to func_00169398, and func_00169398 reads it (mov.s $f21,$f12); no accepted source carries this f32 parameter; return type void kept from the accepted declarations
extern "C" void func_001980d0(u32, u32, u32, u32, f32);
extern "C" u32 func_001de168(...);
// why: parameters derived from registers (only a0 and a1 are set before the jal); no accepted call site, and its only definition (tiny_wrappers_more.cpp) is a generic four-word placeholder thunk
extern "C" void func_001dcc00(u32, u32);
extern "C" u32 func_001050d8(...);
// why: accepted declaration (001ad158) has C++ linkage, which fails the isolated probe link
extern "C" void func_001c1308(u32 *arg1, u32 arg2, s32 arg3, u32 arg4, u32 arg5);

void func_001c2490(u32 object, u32 arg1, u32 arg2, u32 arg3, s32 arg4, u32 arg5, u32 arg6) {
    u32* words = (u32*)object;
    func_001980d0(object, arg1, 4, (u32)D_01d49520, 0.0f);
    words[0] = (u32)D_00351408;
    words[0x162] = words[0x162] | 0x100000;
    u32 child = func_001de168(object + 156, arg2, 0, 1, 0, 0);
    func_001dcc00(child, arg3);
    u32 block = func_001050d8(56);
    func_001c1308((u32*)block, child, arg4, arg5, arg6);
    words[0x27d] = block;
}
