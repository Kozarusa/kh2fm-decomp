#include "../common/types.h"
struct MenuItem {
    void (**table)(MenuItem*);
    u8 rest[436];
};
extern "C" MenuItem* D_0035f3c4;
extern "C" s32 D_0035f3c8;
extern "C" s32 D_0035f3cc;
extern "C" s32 D_0035f3d0;
extern "C" void func_00106420(u32);

// Preserve original registry aliases.
void func_0028c4f8() asm("_ZN2Tz8MenuItem6updateEv");

void func_0028c4f8() {
    MenuItem* items;
    MenuItem* item;
    if (D_0035f3c8 != 0) {
        items = D_0035f3c4;
        if (items != 0) {
            item = items + 32;
        // why: goto loop keeps the test at the top (original is not rotated, ends with b and nop)
        first_loop:
            if (items != item) {
                item--;
                item->table[3](item);
                goto first_loop;
            }
            func_00106420((u32)items);
            D_0035f3c4 = 0;
        }
        D_0035f3c4 = (MenuItem*)D_0035f3c8;
        D_0035f3cc = D_0035f3d0;
        D_0035f3c8 = 0;
        D_0035f3d0 = 0;
    } else {
        items = D_0035f3c4;
        if (items != 0) {
            item = items + 32;
        // why: goto loop keeps the test at the top (original is not rotated, ends with b and nop)
        second_loop:
            if (items != item) {
                item--;
                item->table[3](item);
                goto second_loop;
            }
            func_00106420((u32)items);
            D_0035f3c4 = 0;
        }
        D_0035f3c4 = 0;
    }
}
