#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" bool func_00112d28(s64);

s32 func_0010cce0(s32 node) {
    for (;;) {
        node = func_001b9bc8(node);
        if (node == 0 || func_00112d28(node)) {
            break;
        }
    }
    return node;
}
