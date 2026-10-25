#include "../common/types.h"
extern "C" u8 D_0032e020[];
extern "C" s32 func_00188fe0(...);
extern "C" s32 func_00189200(s32,s32);
extern "C" void func_00188958(u32,u32);
extern "C" u32 func_001891b8(s32,u16);
extern "C" u32 func_001a3188(...);

void func_001c2d88(u8* record) {
    register u32 form asm("$18") = 0; // why: original keeps the form record in s2 and the loop mask in s3
    // why: the register hint gives the original saved-register assignment for the table pointer
    register u32 table = 0;
    if ((record[2] & 0x80) != 0) {
        u8 kind = record[2];
        form = func_00189200((s32)D_0032e020, kind & 0x7f);
    } else {
        table = func_00188fe0(D_0032e020, record[2]);
    }
    if (table != 0) {
        u8* entry = (u8*)table;
        entry[5] = entry[4] = record[3];
        entry[7] = entry[6] = record[4];
        entry[8] = record[5];
        entry[9] = record[6];
        entry[10] = record[7];
        entry[11] = record[8];
        entry[16] = record[9];
        entry[17] = record[10];
        func_00188958(table, record[11]);
    }
    u16* slot = (u16*)(record + 12);
    u32 mask = ~0x8000;
    s32 count = 31;
    do {
        u16 ability = *slot;
        if (ability != 0) {
            if (form == 0) {
                func_001a3188(ability & mask, record[2], ability >> 15);
            } else {
                func_001891b8(form, ability);
            }
        }
        slot++;
        count--;
    } while (count >= 0);
}
