#include "../common/types.h"
struct Pair { s32 first; s32 second; };
extern "C" Pair D_01c6cba0;

s32 func_001a8510() {
    s32 value = D_01c6cba0.first - D_01c6cba0.second + 8;
    return value % 8;
}