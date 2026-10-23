#include "../common/types.h"
extern "C" s32 D_0035dad0;
extern "C" s32 D_0035dad4;
extern "C" s32 D_0035dac4;
extern "C" s32 D_0035dacc;
extern "C" s32 D_0035dac8;
extern "C" s32 D_0035dad8;
extern "C" u8 D_0035dade;
extern "C" u8 D_0035dadd;
extern "C" void func_00224940();

// Preserve original registry aliases.
void func_00224780(s32 value) asm("_Z16u_call4_00224780jjjj");

void func_00224780(s32 value) {
    D_0035dad0 = value;
    D_0035dade = 0;
    D_0035dad4 = 5;
    D_0035dadd = 0;
    D_0035dac4 = 0;
    D_0035dac8 = 0;
    D_0035dacc = 0;
    D_0035dad8 = 0;
    func_00224940();
}
