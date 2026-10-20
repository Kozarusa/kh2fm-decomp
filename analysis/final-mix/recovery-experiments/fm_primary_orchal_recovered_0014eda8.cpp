#include "../common/types.h"
extern "C" s32 D_0034a400;
extern "C" s32 D_0034a408[];
extern "C" void func_002bc358(s32, s32);

void func_0014eda8() {
    s32 index = 0;
    if (D_0034a400 > 0) {
        s32* pointer = D_0034a408;
        do {
            s32 handle = *pointer;
            pointer++;
            if (handle != -1) {
                func_002bc358(handle, 1);
            }
            index++;
        } while (index < D_0034a400);
    }
}
