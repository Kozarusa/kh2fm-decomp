#include "../common/types.h"

extern "C" void func_0023c098(u32);
extern "C" void func_002369f0(u32);
extern "C" s32 func_0023ee68(u32);
extern "C" char D_0035eb98;
extern "C" char D_00347f98;

s32 func_0031ce70(u32* object) {
    object[0] = (u32)(long)&D_0035eb98;
    func_0023c098((u32)(long)(object + 0xc));
    func_002369f0((u32)(long)(object + 6));
    object[0] = (u32)(long)&D_00347f98;
    return func_0023ee68((u32)(long)object);
}
