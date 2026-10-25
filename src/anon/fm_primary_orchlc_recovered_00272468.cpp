#include "../common/types.h"
struct Entry6 {
    s16 first;
    s16 second;
    s16 value;
};
extern "C" Entry6 D_00373a30[];
extern "C" u32 D_0035f04c;
extern "C" u32 func_00287bc0(void);       // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" u32 func_00257770(void);       // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" s32 func_002570a0(...);        // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" u8 func_00272b60(...);         // copied from fm_primary_capacity_recovered_00303c48.cpp
extern "C" u32 func_00139d78(...);        // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" u32 func_00138c10(s32,u32);    // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" u32 func_0028be58(...);        // copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" void func_0028bd60(u32);       // copied from tozawa/cmenu_slbase.cpp

void func_00272468() {
    s32 value = 228;
    u32 mode = func_00287bc0();
    u32 list = func_00257770();
    if (mode - 26 >= 2) {
        Entry6* entry = &D_00373a30[func_00272b60(func_002570a0(26))];
        asm("" : "+r"(entry)); // why: original forms the entry address first, then loads at offset 4
        value = entry->value;
    }
    if (list != 0 && func_00139d78(list) != 0 && *(s32*)(list + 388) != value) {
        func_00138c10(list, value);
    }
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028bd60(D_0035f04c);
    }
}
