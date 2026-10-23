#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" bool func_00112d28(s64);

s32 func_0010cce0(s32 node) {
    while ((node = func_001b9bc8(node)) != 0) {
        if (func_00112d28(node)) {
            break;
        }
    }
    return node;
}
