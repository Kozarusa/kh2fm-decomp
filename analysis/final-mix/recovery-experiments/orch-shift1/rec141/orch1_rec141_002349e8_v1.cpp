#include "../common/types.h"
extern "C" s32 D_0035e370;
extern "C" s32 D_01dae420[];
extern "C" void (*D_01dae41c)(s32);
extern "C" s32 D_0035e36c;
void func_002349e8() {
 D_0035e370 = 0;
 D_01dae420[2] = D_01dae420[1];
 if (D_01dae41c) D_01dae41c(D_0035e36c);
}
