#include "../common/types.h"
extern "C" void func_00106420(...);
extern "C" u8* D_0034c7a0;

void func_00165968() {
    u8* base = D_0034c7a0;
    if (base != 0) {
        s32 count = 64;
        while (count != 0) {
            count--;
        }
        func_00106420();
        D_0034c7a0 = 0;
    }
}
