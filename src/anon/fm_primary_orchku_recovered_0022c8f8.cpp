#include "../common/types.h"
extern "C" f32 D_003711bc;
extern "C" f32 D_003711c0;
extern "C" u8 D_0022c840[];
extern "C" s32 func_001991a8(s32, s32);
// why: no recovered call site or definition exists; the original takes no arguments and its result is not used here
extern "C" void func_002249f8(void);
extern "C" u32 func_002282d8(void);
extern "C" u32 func_00102c18(u32, u32, u32);

// why: void per DEVIATIONS #36: the no-match exit leaves an untouched entry v0; the 001991a8 tail and the 00102c18 path leave direct callee v0 and the 002249f8 tail leaves an integer v0 from its own tail chain; $f0/$f1 on the 200 path hold this function's own loads, so no direct float result is live

void func_0022c8f8(s32 event) {
    switch (event) {
    case 100:
        func_002249f8();
        break;
    case 200: {
        u8* task = (u8*)func_00102c18(1, func_002282d8(), (u32)D_0022c840);
        f32* source = &D_003711bc;
        asm("" : "+r"(source)); // why: original materializes the full address with lui+addiu before the lwc1
        *(f32*)(task + 4) = *source;
        source = &D_003711c0;
        asm("" : "+r"(source)); // why: original materializes the full address with lui+addiu in the same register before the lwc1
        register f32 second asm("$f1") = *source; // why: original loads the second value into $f1
        *(f32*)(task + 8) = second;
        break;
    }
    case 101:
        func_001991a8(135, 0);
        break;
    }
}
