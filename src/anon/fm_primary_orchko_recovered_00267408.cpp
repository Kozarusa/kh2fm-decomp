#include "../common/types.h"
// why: Tz::CmEquip::GetFormMsgTbl (static void*, cmenu_equip.hpp) failed the isolated link in v1; the probe linker script defines only the plain symbol
extern "C" void* func_0026b850();
extern "C" u8* D_0035f010;
extern "C" const void* D_003734d0[10];
extern "C" s32 func_002670a0(s32 value);
// why: no recovered source uses this callee; its tail chain ends in func_001b77d0 whose lhu writes v0, so it returns u16 (arguments from a0/a1)
extern "C" u16 func_00281158(u8* table, s32 index);

u16 func_00267408(s32 value) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_003734d0 (pattern of func_001815d0)
    static const void* targets[10] asm("fm_switch_table_00267408") = {
        &&first, &&second, &&third, &&fourth, &&fifth, &&sixth, &&fixed, &&shifted, &&shifted, &&shifted};
    u16* table = (u16*)func_0026b850();
    u32 slot = func_002670a0(value);
    u16 result = 0;
    s32 index;
    if (slot >= 10) goto done;
    goto *D_003734d0[slot];
first:
    index = 0;
    goto lookup;
second:
    result = table[1];
    goto done;
third:
    result = table[2];
    goto done;
fourth:
    result = table[3];
    goto done;
fifth:
    result = table[4];
    goto done;
sixth:
    result = table[5];
    goto done;
fixed:
    result = 0xc5b1;
    goto done;
shifted:
    index = slot - 6;
lookup:
    result = func_00281158(D_0035f010, index);
done:
    return result;
}
