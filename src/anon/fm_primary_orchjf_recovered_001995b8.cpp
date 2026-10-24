#include "../common/types.h"
extern "C" s32 D_01c62140;

void func_001995b8(s32 from, s32 to) {
    s32 previous = 0;
    s32 node;
    while ((previous = node = ({
                s32 next;
                if (previous == 0) {
                    next = D_01c62140;
                } else {
                    next = *(s32*)(previous + 20);
                }
                next;
            })) != 0) {
        if (*(s32*)(node + 12) == from) {
            *(s32*)(node + 12) = to;
        }
    }
}
