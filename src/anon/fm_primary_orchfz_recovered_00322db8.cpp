#include "../common/types.h"
extern "C" u8 D_0035eb98[];
extern "C" u8 D_00347f98[];
extern "C" void func_0023c098(u8*);
extern "C" void func_002369f0(u8*);
extern "C" s32 func_0023ee68(u8*);

s32 func_00322db8(u8* object) {
    *(u8**)object = D_0035eb98;
    func_0023c098(object + 0x30);
    func_002369f0(object + 0x18);
    *(u8**)object = D_00347f98;
    return func_0023ee68(object);
}
