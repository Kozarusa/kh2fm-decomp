#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" s32 func_0016e920(s64);
extern "C" s32 func_001b9bc8(s32);

s32 func_0016b740(s64 id) {
    s32 node = D_0034e948;
    if (id != 0x236) {
        s32 data = func_0016e920(id);
        node = 0;
        do {
            node = func_001b9bc8(node);
            if (node == 0) {
                return 0;
            }
        } while (*(s32*)(node + 8) != data);
    }
    return node;
}
