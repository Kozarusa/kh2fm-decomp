#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef void (*VirtualFn)(void*, void*, s32);
extern "C" s32 func_002cebb0();
extern "C" s32* D_00361f60;

void func_001786e0(u8* object) {
    Quad buffer;
    Quad* target = (Quad*)(object + 0x10);
    // why: VU macro zero-fill of a 16-byte vector; noreorder keeps it out of the jal delay slot, the output operand keeps the target in a saved register
    asm volatile(
        ".set noreorder;"
        "vsub.xyzw $vf1,$vf0,$vf0;"
        "sqc2 $vf1,0(%0);"
        ".set reorder" : "+r"(target) : : "memory");
    if (func_002cebb0() != 0) {
        s32* handler = D_00361f60;
        ((VirtualFn)(*(s32**)handler)[9])(&buffer, handler, *(s32*)(object + 0xb38) + 0x30);
        if (target != &buffer) {
            *target = buffer;
        }
    }
}
