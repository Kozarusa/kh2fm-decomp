#include "../common/types.h"
extern "C" u32 D_0035de3c;
extern "C" u32 D_0035de30;
extern "C" u32 D_0035de34;
extern "C" u32 D_0035de38;
extern "C" u8 D_0035de27;
extern "C" s32 func_00102670(u32, u32);

// why: void per DEVIATIONS #36: the D_0035de3c == 0 exit leaves the untouched entry v0

void func_00228240() {
    if (D_0035de3c != 0) {
        if (D_0035de30 != 0) {
            func_00102670(D_0035de3c, D_0035de30);
            D_0035de30 = 0;
        }
        if (D_0035de34 != 0) {
            func_00102670(D_0035de3c, D_0035de34);
            D_0035de34 = 0;
        }
        if (D_0035de38 != 0 && D_0035de27 == 0) {
            func_00102670(D_0035de3c, D_0035de38);
            D_0035de38 = 0;
        }
        D_0035de3c = 0;
    }
}
