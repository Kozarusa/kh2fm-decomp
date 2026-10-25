#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" s32 *func_001b6fb0(u32,u32);
// why: exact types of the accepted definition fm_primary_oneword_recovered_001b72c0.cpp; extern "C" because its C++ linkage fails the isolated probe link (lg263 v1)
extern "C" void func_001b72c0(u32, u32, u32, int);
extern "C" void func_001b7428(u8*);
extern "C" void func_001a1460(u32);

void func_001b71e8(u32 owner, u8* entry, u8* sheet) {
    u8* table = D_0032bb30;
    asm("" : "+r"(table)); // why: original keeps the D_0032bb30 base in s3 and reads +0x36e0 from it
    s32 first = 1;
    while (1) {
        if (entry[15] >= 99) {
            return;
        }
        if (*func_001b6fb0(owner, entry[15]) > *(s32*)(table + 0x36e0)) {
            return;
        }
        entry[15]++;
        func_001b72c0((u32)func_001b6fb0(owner, entry[15]), owner, entry[15], entry[14]);
        if (sheet != 0) {
            if (first) {
                first = 0;
                func_001b7428(sheet);
            }
            func_001a1460(*(u32*)(sheet + 0x48c));
        }
    }
}
