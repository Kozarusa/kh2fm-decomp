#include "../common/types.h"
struct WordPair {
    u32 first;
    u32 second;
};
extern "C" WordPair D_0034dca0;
extern "C" WordPair D_0034dcb8;

void func_00170ee8(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        // why: original keeps the object pointer in t7 and the high half in t6
        register WordPair* pair asm("$15") = &D_0034dca0;
        pair->first = 0;
        pair->second = 0;
    }
    if (priority == 0xffff && initialize == 1) {
        // why: original keeps the object pointer in t7 and the high half in t6
        register WordPair* pair asm("$15") = &D_0034dcb8;
        pair->first = 0;
        pair->second = 0;
    }
}
