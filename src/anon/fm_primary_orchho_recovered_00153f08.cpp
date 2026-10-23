#include "../common/types.h"
extern "C" u8 D_00347f98[];
extern "C" u8 D_0035eb98[];
extern "C" u8 D_0034a7a0[];
extern "C" u8* func_0023ee30(s32);
extern "C" void func_0031a838(u32);
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
extern "C" void func_00153ea0(u8*, s32, s32, s32, s32);

// Preserve original registry aliases.
u8* func_00153f08(s32 name, s32 size) asm("_ZN2dk6Camera20singleCrossFadeStartEf");

u8* func_00153f08(s32 name, s32 size) {
    u8* object = func_0023ee30(164);
    *(u8**)(object + 0) = D_00347f98;
    func_0031a838((u32)(object + 12));
    *(u8**)(object + 0) = D_0035eb98;
    func_002369a0(object + 24);
    func_0023c008(object + 48);
    *(u8**)(object + 0) = D_0034a7a0;
    func_00153ea0(object, name, 4800, size, 0);
    return object;
}
