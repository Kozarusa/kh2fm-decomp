#include "../common/types.h"
extern "C" void func_00192800(u64, u64, u32*);

void func_00192818(u64 first, u64 second, u32* source) {
    u32 snapshot[6];
    u32 word0 = source[0];
    u32 word1 = source[1];
    u32 word2 = source[2];
    u32 word3 = source[3];
    u32 word4 = source[4];
    u32 word5 = source[5];
    snapshot[2] = word2;
    snapshot[0] = word0;
    snapshot[1] = word1;
    snapshot[3] = word3;
    snapshot[4] = word4;
    snapshot[5] = word5;
    func_00192800(first, second, snapshot);
}
