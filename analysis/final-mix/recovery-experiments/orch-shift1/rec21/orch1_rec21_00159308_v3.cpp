#include "../common/types.h"
extern "C" f32 D_0036b334;
extern "C" s32 D_0034aa08;
extern "C" u64 func_00162098();
extern "C" void func_00162058(f32);

void func_00159308(u8* object) {
    if ((*(u64*)(object + 8) & 0x400000) != 0) {
        if (func_00162098() == 0) {
            D_0034aa08 = D_0034aa08 ^ 1;
            func_00162058(D_0036b334);
        }
    }
}
