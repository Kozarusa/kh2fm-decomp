#include "../common/types.h"
struct Entry { s32 a; s32 b; s32 c; };
extern "C" Entry D_01c94090[];

void func_001afa50() {
    Entry* pointer = D_01c94090;
    Entry* end = pointer + 3;
    do {
        pointer->a = 0;
        pointer->b = -1;
        pointer->c = -1;
        pointer++;
    } while (pointer < end);
}
