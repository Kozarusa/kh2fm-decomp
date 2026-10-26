#include "../common/types.h"
extern "C" u32 D_0033cae8[];
bool func_002f1ae0(u32 index) {
    u32 bits = D_0033cae8[index >> 5];
    u32 mask = 1u << (index & 31);
    return (bits & mask) != 0;
}
