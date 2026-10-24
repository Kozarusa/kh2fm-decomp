#include "../common/types.h"
extern "C" s16 D_0034a458[19][3];

void func_0014fba0(void) {
    s32 row;
    s32 column;

    for (row = 0; row < 19; row++) {
        for (column = 0; column < 3; column++) {
            D_0034a458[row][column] = 0;
        }
    }
}
