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
    s32 result = 0;
    if (a->f50 != 0) {
        u8 type = b->cc;
        u8 flag;
        if (type == 1 || type == 3 || type == 2) {
            if (a->f54 == 0) {
                return 0;
            }
            flag = b->c9;
        } else {
            flag = b->c9;
        }
        result = 1;
        if (flag != 0) {
            result = 0;
            if (a->f58 != 0) {
                result = 1;
            }
        }
    }
    return result;
}
