#include "../common/types.h"
struct WordPair {
    s32 first;
    s32 second;
};
extern "C" s32 D_0032b91c;
extern "C" s32 D_004f6288;
extern "C" WordPair D_004f6290;

// Preserve original registry aliases.
void func_0016d230(s32 mode, s32 value) asm("_Z16wtarget_0016d230jjjj");

void func_0016d230(s32 mode, s32 value) {
    if (value == 0xffff) {
        if (mode == 1) {
            D_004f6288 = D_0032b91c;
        }
    }
    if (value == 0xffff) {
        if (mode == 1) {
            register WordPair* pair asm("$15") = &D_004f6290; // why: original keeps the object pointer in t7 and the high half in t6
            pair->first = 0;
            pair->second = 0;
        }
    }
}
