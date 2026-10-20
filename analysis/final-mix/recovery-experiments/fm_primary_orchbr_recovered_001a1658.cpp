#include "../common/types.h"
extern "C" s32 func_001a1540(s32);
extern "C" s32 func_001a15d0(s32, s32);

s32 func_001a1658(s32 kind, s32 slot) {
    switch (kind) {
    case 1:
    case 14:
        return func_001a15d0(kind, slot);
    case 0:
        return 0;
    default:
        return func_001a1540(kind);
    }
}
