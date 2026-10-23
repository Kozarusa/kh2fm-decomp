#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8 D_00348710[];
extern "C" s32 func_00140dc0();
extern "C" void func_0013fd78(u8*);
extern "C" u32 func_0013f558(...);
extern "C" u32 func_00140b68(u8*, u32);

u32 func_00140f78(kn::FVector* target, kn::FVector* position) {
    s32 mode = func_00140dc0();
    u8* camera = D_00348710;
    *(s32*)(camera + 64) = 0;
    func_0013fd78(camera);
    func_0013f558(camera);
    u32 result = func_00140b68(camera, 1);
    *target = *(kn::FVector*)(camera + 16);
    *position = *(kn::FVector*)camera;
    *(s32*)(camera + 64) = mode;
    return result;
}
