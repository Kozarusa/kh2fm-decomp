#include "../common/types.h"
struct Entry { s32 a; s32 b; s32 c; };
extern "C" Entry D_01c94090[];

void func_001afa50() {
    Entry* pointer = D_01c94090;
    s32 end = (s32)pointer + 36;
    do {
        pointer->a = 0;
        pointer->b = -1;
        pointer->c = -1;
        pointer++;
    } while ((s32)pointer < end);
}
