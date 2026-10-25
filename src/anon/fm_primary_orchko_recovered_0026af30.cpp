#include "../common/types.h"
struct InfoEntry {
    u16 field0;
    u8 field2;
    u8 field3;
    u16 field4;
};
extern "C" u32 D_0035f010;
extern "C" u32 D_0035f0ec;
extern "C" u32 D_0035f01c;
extern "C" u32 func_001a3188(...);
extern "C" s32 func_001a3458(s32,s32);
extern "C" u32 func_00257070(...);
extern "C" u32 func_00281180(...);
extern "C" u32 func_0028b040(...);
// why: no recovered call site carries this callee; the definition is the member
// Tz::ItemInfo::GetInfo (void*, this in a0, tz/ui_accessors.cpp), so the object is passed in a0.
extern "C" InfoEntry* func_00281f20(u32);

s32 func_0026af30(s32 index, s32 item) {
    u32 sheet = func_00281180(D_0035f010, func_00257070(1));
    u8* entry = (u8*)(index * 2 + *(s32*)(sheet + 580));
    u16 current = *(u16*)(entry + 52);
    if (current != 0) {
        func_001a3188(current, 100, 0);
    }
    InfoEntry* info = func_00281f20(D_0035f0ec);
    s32 slot = func_0028b040(D_0035f01c) - 1;
    asm("" : "+r"(slot)); // why: original subtracts 1 before the branch instead of folding it into the lbu offset
    if (item == 0 || info[slot].field2 != 0) {
        *(u16*)(entry + 52) = item;
        *(u16*)(entry + 68) = 0;
        if (item != 0) {
            func_001a3458(item, 100);
        }
    } else {
        *(u16*)(entry + 68) = item;
        *(u16*)(entry + 52) = 0;
    }
    return 1;
}
