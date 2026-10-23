#include "../common/types.h"
struct Slot {
    s32 first;
    s32 key;
    s32 last;
};
extern "C" Slot D_01c94090[];

s32 func_001afe30(s32 value) {
    s32 index;
    for (index = 0; index < 3; index++) {
        if (D_01c94090[index].key == value) return index;
    }
    return -1;
}
