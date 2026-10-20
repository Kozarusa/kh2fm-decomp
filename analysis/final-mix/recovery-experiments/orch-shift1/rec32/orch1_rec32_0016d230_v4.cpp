#include "../common/types.h"
extern "C" s32 D_0032b91c;
extern "C" s32 D_004f6288;
extern "C" s32 D_004f6290;

void func_0016d230(s32 mode, s32 value) {
    s32* pointer = &D_004f6290;
    if (value == 0xffff) {
        if (mode == 1) {
            D_004f6288 = D_0032b91c;
        }
    }
    if (value == 0xffff) {
        if (mode == 1) {
            D_004f6290 = 0;
            pointer[1] = 0;
        }
    }
}