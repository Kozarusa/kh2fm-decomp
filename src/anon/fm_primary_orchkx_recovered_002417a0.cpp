#include "../common/types.h"
// why: the original reloads the table pointer after every word store in the loop; declaring it as a word lets those s32 stores alias it
extern "C" s32 D_0035ec94;
// why: no recovered source declares or calls func_002408d0; a0 is set before each jal and its v0 is compared with slt as a full word
extern "C" s32 func_002408d0(s32);

void func_002417a0(void) {
    s32 table = D_0035ec94;
    if (table == 0) return;
    s16 limit = *(s16*)(table + 2);
    if (limit < 0) return;
    if (*(s8*)(table + 5) != 0) {
        if (!(limit < func_002408d0(1))) return;
    } else {
        if (!(limit < func_002408d0(0))) return;
    }
    for (s32 index = 0; index < 99; index++) {
        s32* state = (s32*)(index * 32 + D_0035ec94 + 8);
        if (*state == 0) *state = 64;
    }
}
