#include "../common/types.h"
extern u8 D_0035de24;
extern u8 D_0035de25;
extern s32 D_0035de28;
extern s32 D_0035de4c;
extern s32 D_0035dd04;
extern s32 D_0035de50;
extern u32 D_0035dd08[];
extern s32 D_0035de2c;
extern u8 D_0035de56;
extern u8 D_0035de70[];
// why: no recovered source calls these three; no argument registers are set before each jal and the results are discarded.
// why: extern "C" because the isolated probe linker script defines only the plain (unmangled) symbol
extern "C" void func_0022d7c8();
extern "C" void func_00225a00();
extern "C" void func_00225a20();
// why: signature from the accepted definition in fm_primary_twoword_recovered_0022d7e8.cpp; extern "C" for the same linker-script reason
extern "C" void func_0022d7e8(void);

void func_00226fc8(void) {
    D_0035de24 = 0;
    D_0035de25 = 0;
    D_0035de28 = -1;
    func_0022d7c8();
    func_00225a00();
    func_00225a20();
    D_0035de4c = 0;
    D_0035de50 = 0;
    D_0035de2c = 0;
    u32* cursor = D_0035dd08;
    s32 count = 0x3f;
    D_0035de56 = 0;
    D_0035dd04 = -1;
    do {
        *cursor = 0;
        cursor += 1;
        count--;
    } while (count >= 0);
    func_0022d7e8();
    // why: stores the constant vf0 vector (0,0,0,1) to D_0035de70; no C++ operation emits sqc2 of vf0; identical asm text in accepted fm_primary_orchjq_recovered_0019bfd0.cpp
    asm volatile("sqc2 $vf0,0(%0)" : : "r"(D_0035de70) : "memory");
}
