#include "../common/types.h"
struct Block {
    u32 word[6];
};
struct Pair {
    u32 first;
    u32 second;
};
extern "C" u32 func_00192868(...);

u32 func_00192990(u32 handle, u32 value, Block block, Pair* result) {
    register u32 kept asm("$18") = value; // why: original keeps value in s2 and the pair address in s1
    Pair pair;
    pair.first = 0;
    pair.second = 0;
    result->first = 0;
    result->second = 0;
    if (handle != 0) {
        do {
            handle = func_00192868(handle, kept, &block, &pair);
            u32 first = pair.first;
            if (first < result->first) {
                first = result->first;
            }
            u32 second = pair.second;
            if (second < result->second) {
                second = result->second;
            }
            result->first = first;
            result->second = second;
        } while (handle != 0);
    }
    result->first = (result->first + 1) & ~1u;
    result->second = (result->second + 1) & ~1u;
    return handle;
}
