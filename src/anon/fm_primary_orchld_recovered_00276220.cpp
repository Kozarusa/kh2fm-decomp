#include "../common/types.h"
extern "C" s16 D_00373d60[];
extern "C" s16 D_00373d68[];
extern "C" s32 D_0035f14c;
extern "C" s32 D_0035f148;
extern "C" s32 D_0035f210;
extern "C" s32 D_0035f204;
extern "C" s32 D_0035f144;
// why: extern "C" because the probe linker script defines only the plain symbol; the original reads no argument registers before this call is used and the definition takes none
extern "C" u32 func_00276368();
extern "C" void func_00138c10(s32, u64);
extern "C" void func_0028d8c0(u32, u32, u32, u32, u32, s32, s32, u32);

// why: void per DEVIATIONS #36: the only exit follows a final call into func_0028d8c0 or func_00138c10, both accepted void definitions (stale-b)

void func_00276220(s32 mode, s32 index) {
    s16* table;

    if (mode == 0) {
        table = D_00373d60;
    } else {
        table = D_00373d68;
    }
    if (func_00276368() == 0) {
        func_0028d8c0(D_0035f204, 30041, D_0035f14c, D_0035f148, D_0035f210, table[index], -1, 0);
    } else {
        func_00138c10(D_0035f204, table[index]);
    }
    if (index == 0) {
        *(s32*)(D_0035f204 + 392) = table[2];
    } else {
        *(s32*)(D_0035f204 + 392) = -1;
    }
    D_0035f144 = mode;
}
