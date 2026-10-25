#include "../common/types.h"
extern "C" s32 func_0018ca48(u8);       // copied from accepted fm_primary_orchjb_recovered_0018cd28.cpp
extern "C" u32 func_00198580(...);      // copied from accepted fm_primary_orchjj_recovered_0018da18.cpp

// why: void under the 2026-10-20 second mixed-exit ruling: two exits leave the caller v0 untouched, the others leave the direct v0 of the final callee (func_0018ca48 or func_00198580), no float

void func_001b3e88(u8* object, u8* damage) {
    s32 index = -1;
    u8* info = *(u8**)(object + 0x9b4);
    if (info != 0) {
        index = *(s16*)(info + 2);
    }
    if (index < 0) {
        return;
    }
    s32 kind = -1;
    // why: xor form matches the original xori + bnez test (cookbook C6)
    if ((*(s32*)(*(u8**)(object + 0xc) + 4) ^ 0x17) == 0) {
        switch ((*(u8**)(damage + 0x20))[0x2b]) {
        case 0:
            kind = 0;
            break;
        case 1:
            kind = 2;
            break;
        }
    } else {
        switch (func_0018ca48(damage[0x27])) {
        case 1:
        case 3:
        case 5:
            kind = 0;
            break;
        case 4:
            kind = 2;
            break;
        }
    }
    if (kind >= 0) {
        func_00198580(object, index * 1000 + kind + (object[0x7fc] & 1));
        object[0x7fc]++;
    }
}
