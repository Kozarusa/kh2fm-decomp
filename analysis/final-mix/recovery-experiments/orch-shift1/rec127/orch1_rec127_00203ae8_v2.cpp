#include "../common/types.h"

struct A {
    u8 pad[80];
    s32 f50;
    s32 f54;
    s32 f58;
};

struct B {
    u8 pad[201];
    u8 c9;
    u8 pad2[2];
    u8 cc;
};

s32 func_00203ae8(A* a, B* b) {
    if (a->f50 == 0) {
        return 0;
    }
    u8 type = b->cc;
    if (type == 1 || type == 3 || type == 2) {
        if (a->f54 == 0) {
            return 0;
        }
    }
    if (b->c9 == 0) {
        return 1;
    }
    if (a->f58 != 0) {
        return 1;
    }
    return 0;
}

