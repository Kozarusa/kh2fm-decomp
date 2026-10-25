#include "../common/types.h"
// why: the original reloads this pointer at the join after the first store instead of reusing it
extern "C" u8* volatile D_0035f20c;
extern "C" u32 D_0035f14c;
extern "C" u32 D_0035f148;
extern "C" u32 D_0035f210;
// why: result type from the testing call site in fm_primary_orchlb_recovered_00257388.cpp; the one pointer argument is read from a0 here
extern "C" u32 func_00139d78(u8*);
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);

void func_00275d10() {
    if (func_00139d78(D_0035f20c) == 0) {
        func_0028d980(D_0035f20c, 0x7558, D_0035f14c, D_0035f148, D_0035f210, 0x2f, 0x30, -1, 0);
        *(s32*)(D_0035f20c + 0x1b0) = 2;
    }
    if (func_00139d78(D_0035f20c + 0x1b4) == 0) {
        func_0028d980(D_0035f20c + 0x1b4, 0x7558, D_0035f14c, D_0035f148, D_0035f210, 0x32, 0x33, -1, 0);
        *(s32*)(D_0035f20c + 0x364) = 2;
    }
}
