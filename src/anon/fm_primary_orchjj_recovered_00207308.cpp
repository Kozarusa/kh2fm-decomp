#include "../common/types.h"

struct A {
    u8 pad[16];
    s32 f10;
    s32 f14;
    s32 f18;
};

struct B {
    u8 pad[257];
    u8 c101;
    u8 pad2[4];
    u8 c106;
};

s32 func_00207308(A* a, B* b) {
    if (a->f10 == 0) {
        return 0;
    }
    if (b->c106 != 0) {
        if (a->f14 == 0) {
            return 0;
        }
    }
    if (b->c101 != 0 && a->f18 == 0) {
        return 0;
    }
    return 1;
}
