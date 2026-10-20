#include "../common/types.h"
struct WordPair {
    u32 first;
    u32 second;
};
extern "C" f32 D_0036ccd8;
extern "C" f32 D_01c60cd0;
extern "C" WordPair D_01c60cd8;

void func_0018f0b0(s32 initialize, s32 priority) {
    if (priority == 0xffff && initialize == 1) {
        f32* source = &D_0036ccd8;
        // why: original forms the full source address before the offset-0 load
        asm("" : "+r"(source));
        f32 value = *source;
        // why: keeps the store address formed after the load, reusing t7
        asm volatile("" ::: "memory");
        D_01c60cd0 = value;
    }
    if (priority == 0xffff && initialize == 1) {
        // why: original keeps the object pointer in t7 and the high half in t6
        register WordPair* pair asm("$15") = &D_01c60cd8;
        pair->first = 0;
        pair->second = 0;
    }
}
