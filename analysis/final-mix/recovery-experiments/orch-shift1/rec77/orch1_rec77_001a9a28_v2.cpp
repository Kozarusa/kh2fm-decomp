#include "../common/types.h"

void func_001a9a28(u32 mode, u32* src, s32* dst) {
    switch (mode) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        *dst = *dst - *src;
        break;
    }
}
