#include "../common/types.h"

u32 func_00145580(s16* first, s16* second) {
    if (first[3] < second[0]) return 0;
    if (second[3] < first[0]) return 0;
    if (first[4] < second[1]) return 0;
    if (second[4] < first[1]) return 0;
    if (first[5] < second[2]) return 0;
    return !(second[5] < first[2]);
}