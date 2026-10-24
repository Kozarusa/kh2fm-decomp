#include "../common/types.h"
extern "C" s32 D_00361fa4;
extern "C" s32 D_00361fa0;
extern "C" void func_00182f38(void);

void func_002cf938(u8 flag) {
    if (flag != 0 && D_00361fa4 != 0) {
        for (s32 index = 0; index < D_00361fa0; index++) {
            *(s32*)(D_00361fa4 + index * 0x28) = 0;
        }
    }
    func_00182f38();
}
