#include "../common/types.h"

extern "C" u8 D_003629e8[];
extern "C" void func_002e4a90(u32);
extern "C" void func_002cea28(u32);
extern "C" u32 func_00105110(u32);

u32 func_002dc788(u32 object) {
    *(u32*)object = (u32)D_003629e8;
    func_002e4a90(object + 256);
    func_002cea28(object);
    return func_00105110(object);
}
