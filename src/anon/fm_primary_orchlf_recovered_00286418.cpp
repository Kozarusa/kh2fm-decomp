#include "../common/types.h"
extern "C" u32* D_0035f2e4;
// why: no recovered declaration exists; no argument register is set before the jal and its v0 is tested against zero
extern "C" s32 func_002812e0();

s32 func_00286418(s32 index) {
    s32 result;
    if (index >= 0) {
        u32* words = D_0035f2e4 + ((u32)index >> 5);
        result = (words[50] & (1 << (index & 0x1f))) != 0;
        if (func_002812e0() != 0 && index < 5) {
            result = 0;
        }
    } else {
        s32 item = 0;
        do {
            u32* words = D_0035f2e4 + ((u32)item >> 5);
            result = (words[50] & (1 << (item & 0x1f))) != 0;
            if (func_002812e0() != 0 && item < 5) {
                result = 0;
            }
            if (result != 0) {
                break;
            }
            item++;
        } while (item < 9);
    }
    return result;
}
