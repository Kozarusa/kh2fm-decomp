#include "../common/types.h"
extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319fb0(u32);
extern "C" u32 func_00105110(u32);
extern "C" char D_0034ee08;

u32 func_00321910(u32 object) {
    *(u32*)object = (u32)(long)&D_0034ee08;
    func_0019f9a8(object + 2568);
    func_001c0248(object + 2640);
    func_00319fb0(object);
    return func_00105110(object);
}
