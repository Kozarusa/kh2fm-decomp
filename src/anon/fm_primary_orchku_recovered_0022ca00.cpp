#include "../common/types.h"
extern "C" u8* D_0035de50;
extern "C" s32 D_0035de20;
// why: return and parameter types copied from the accepted definition in fm_primary_oneword_recovered_00225b00.cpp (a C++ definition); declared extern "C" so the isolated probe links against the plain symbol, as for func_0022b7f0 in lg371 0022b898 v1, whose C++ form failed that link
extern "C" u32 func_00225b00(s32);
extern "C" u32 func_00227d10(...);
extern "C" u32 func_001ba028(...);
// why: no recovered source calls 00227d58; one s16 argument in a0 and a word result stored by the caller, derived from registers
extern "C" u32 func_00227d58(s32);

void func_0022ca00(void) {
    u8* table = D_0035de50;
    if (table != 0) {
        s32 total = *(s16*)(table + 4);
        register s32 limit asm("$20") = D_0035de20; // why: original keeps the limit in s4 and the tail pointer in s5 (v4 swapped them)
        s16* entry = (s16*)(table + 8);
        if (total > 0) {
            s32 count = total;
            do {
                s32 first = entry[1];
                s16* tail = entry + 4;
                s32 second = entry[2];
                if (func_00225b00(first) == 0 && limit >= first && limit < second) {
                    u8* work = (u8*)func_00227d10(entry[0]);
                    if (work != 0 && *(u32*)(work + 8) != 0) {
                        if (func_001ba028(*(u32*)(work + 8)) != 0) {
                            u32 value = func_00227d58(entry[0]);
                            *(u32*)(*(u32*)(work + 8) + 1704) = value;
                            *(u32*)(*(u32*)(work + 8) + 1904) = (u32)tail;
                        }
                    }
                }
                count--;
                entry += 46;
            } while (count != 0);
        }
    }
}
