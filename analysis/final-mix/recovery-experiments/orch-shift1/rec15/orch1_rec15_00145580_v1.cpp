#include "../common/types.h"

u32 func_00145580(s16* first, s16* second) {
    u32 result = 0;
    if (second[0] <= first[3] && first[0] <= second[3] && second[1] <= first[4] && first[1] <= second[4] && second[2] <= first[5]) {
        result = first[2] <= second[5];
    }
    return result;
}