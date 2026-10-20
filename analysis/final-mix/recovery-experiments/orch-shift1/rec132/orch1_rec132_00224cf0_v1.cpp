#include "../common/types.h"
extern "C" u32 func_00224c20(void);
extern "C" u32 D_0035db18;
void func_00224cf0(void) {
    switch (func_00224c20()) {
    case 0: break;
    case 1: case 2: case 4: case 5: D_0035db18 = 0x700000; break;
    case 3: D_0035db18 = 0x600000; break;
    }
}