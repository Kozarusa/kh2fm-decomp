#include "../common/types.h"
extern "C" bool func_002282f0(...);
extern "C" u32 func_00227ca8(void*);
// why: type follows the accepted definition in fm_primary_oneword_recovered_00225b00.cpp; extern "C" because the probe linker script defines only the plain symbol
extern "C" u32 func_00225b00(s32 value);
// why: no accepted declaration; derived from registers (a0 argument, v0 result stored by this function)
extern "C" s32 func_002bc238(s32 id);
// why: copied from the call sites in fm_primary_orchal_recovered_0014eda8.cpp and fm_primary_orchda_recovered_001e0058.cpp; extern "C" because the probe linker script defines only the plain symbol
extern "C" void func_002bc358(s32, s32);
extern "C" s32 D_0035e35c;
extern "C" s32 D_0035db60[];

void func_00232c88(u8* object) {
    if (func_002282f0(*(s16*)(object + 12)) != 0)
        return;
    if (*(s16*)(object + 6) == 0) {
        // why: s32 because the original compares the u32 result signed (slti v0,1001)
        s32 value = func_00227ca8(object + 8);
        s32 id = value - 1000;
        if (value <= 1000) {
            id = D_0035e35c * 1000 + value;
        }
        if (func_00225b00(*(s16*)(object + 12)) == 0) {
            D_0035db60[*(s16*)(object + 4)] = func_002bc238(id);
        }
    } else {
        if (func_00225b00(*(s16*)(object + 12)) == 0) {
            // why: a separate local for the table entry gives the original t7/t6 register assignment
            s32 handle = D_0035db60[*(s16*)(object + 4)];
            func_002bc358(handle, 240);
        }
    }
}
