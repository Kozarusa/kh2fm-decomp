#include "../common/types.h"
struct WordPair {
    u32 first;
    u32 second;
};
extern "C" WordPair D_0034dca0;
extern "C" WordPair D_0034dcb8;

static inline void ClearPair(WordPair* pair) {
    pair->first = 0;
    pair->second = 0;
}

void func_00170ee8(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        ClearPair(&D_0034dca0);
    }
    if (priority == 0xffff && initialize == 1) {
        ClearPair(&D_0034dcb8);
    }
}
