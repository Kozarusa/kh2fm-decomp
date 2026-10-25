#include "../common/types.h"
extern "C" u32 D_0035f680[];
extern "C" u8* D_0035f660;
extern "C" void func_001a98e8(u8*, s32, u8*, u32, s32); // copied from fm_primary_orchko_recovered_0026a9f8.cpp
extern "C" void func_001a9ae8(u8*, s32, s32, u32); // copied from fm_primary_orchko_recovered_0026a9f8.cpp
// why: no recovered call site; original passes one word in a0 and uses v0 as a pointer to three words
extern "C" s32* func_002b6118(u32);

void func_002b6138(s32 x, s32 y, u32 unused, u32 color, u32 key) {
    u8 buffer[96];
    s32 found = -1;
    s32 index;
    for (index = 0; index < 4; index++) {
        if (D_0035f680[index] == key) {
            found = index;
            break;
        }
    }
    u32* entry = (u32*)(D_0035f660 + found * 40);
    index = 0;
    do {
        if (entry[1] == 0) {
            return;
        }
        index++;
        s32* info = func_002b6118(entry[0]);
        func_001a98e8(buffer, 1, (u8*)entry[1], 14, info[2]);
        entry += 2;
        func_001a9ae8(buffer, info[0] + x, info[1] + y, color);
    } while (index < 5);
}
