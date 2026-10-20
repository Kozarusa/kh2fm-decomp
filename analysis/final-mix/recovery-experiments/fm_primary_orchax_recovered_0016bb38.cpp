#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);

void func_0016bb38(u64 a, u64 b) {
    s32 node = 0;
    while ((node = func_001b9bc8(node)) != 0) {
        (*(void (**)(s32, u64, u64))(*(s32*)node + 0x34))(node, a, b);
    }
}
