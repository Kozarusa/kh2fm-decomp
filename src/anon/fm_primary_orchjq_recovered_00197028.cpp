#include "../common/types.h"
extern "C" const void* D_0036d078[10];
extern "C" f32 D_00349e10;
extern "C" s32 func_002ee530(u8*);
extern "C" void func_00197148(u8*);
extern "C" void func_00197280(u8*);
extern "C" s32 func_00197318(u8*);
extern "C" void func_00197390(u32);
extern "C" s32 func_001973f0(u32);
extern "C" void func_00197430(u8*);
extern "C" void func_00197568(u8*);
extern "C" u32 func_001975a0(u32*);

s32 func_00197028(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036d078
    static const void* targets[10] asm("fm_switch_table_00197028") = {
        &&phase0, &&phase1, &&phase2, &&phase3, &&other,
        &&phase5, &&phase6, &&phase7, &&other, &&phase9};
    if (func_002ee530(object) != 0) {
        return 1;
    }
    for (;;) {
        s32 count = *(s32*)(object + 0x34);
        if (count > 0) {
            *(s32*)(object + 0x34) = count - 1;
            return 1;
        }
        f32 timer = *(f32*)(object + 0x38);
        if (0.0f < timer) {
            *(f32*)(object + 0x38) = timer - D_00349e10;
            return 1;
        }
        u32 state = *(u32*)(object + 0x30);
        if (state >= 10) goto other;
        goto *D_0036d078[state];
    phase0:
        func_00197148(object);
        continue;
    phase1:
        func_00197280(object);
        continue;
    phase2:
        func_00197318(object);
        continue;
    phase3:
        func_00197390((u32)object);
        continue;
    phase5:
        func_001973f0((u32)object);
        continue;
    phase6:
        func_00197430(object);
        continue;
    phase7:
        func_00197568(object);
        continue;
    phase9:
        func_001975a0((u32*)object);
        return 0;
    other:
        return 1;
    }
}
