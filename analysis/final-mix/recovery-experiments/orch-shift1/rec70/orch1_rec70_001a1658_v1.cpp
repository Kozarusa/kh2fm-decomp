#include "../common/types.h"
extern "C" s32 func_001a1540(s32);
extern "C" s32 func_001a15d0(s32, s32);

s32 func_001a1658(s32 kind, s32 slot) {
    if (kind == 1) {
        return func_001a15d0(kind, slot);
    }
    if (kind < 2) {
        if (kind == 0) {
            return 0;
        }
    } else if (kind == 14) {
        return func_001a15d0(kind, slot);
    }
    return func_001a1540(kind);
}
