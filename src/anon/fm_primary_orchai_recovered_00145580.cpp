#include "../common/types.h"

u32 func_00145580(s16* first, s16* second) {
    if (first[3] < second[0]) return 0;
    if (first[0] > second[3]) return 0;
    if (first[4] < second[1]) return 0;
    if (first[1] > second[4]) return 0;
    if (first[5] < second[2]) return 0;
    u32 less = first[2] > second[5];
    return less < 1;
}
