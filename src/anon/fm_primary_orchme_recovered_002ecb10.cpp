#include "../common/types.h"
extern "C" f32 D_01e2c060;
extern "C" f32 D_00349e10;
extern "C" s32 func_002eb3b8(u8*);
extern "C" s32 func_002eb098(u8*);
extern "C" void func_002eb1a0(u32 a0);

void func_002ecb10(u32 unused, u8* object) {
    if (func_002eb3b8(object) != 0) {
        return;
    }
    D_01e2c060 = D_01e2c060 + D_00349e10;
    if (D_01e2c060 > 10.0f || func_002eb098(object) != 0) {
        func_002eb1a0((u32)object);
    }
}
