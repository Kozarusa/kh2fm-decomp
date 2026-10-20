#include "../common/types.h"
extern "C" bool func_001883d8(...);
extern "C" u32 func_001880b0(...);
extern "C" u8 D_0036cbb0[];

void func_0018b200(u8* object) {
    if (*(u8*)(*(s32*)(object + 8) + 4) == 15) {
        if (func_001883d8(object + 0x300, D_0036cbb0)) {
            func_001880b0(object + 0x300, D_0036cbb0);
        }
    }
}
