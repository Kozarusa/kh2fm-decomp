#include "../common/types.h"
extern "C" char D_0034ee08;
extern "C" void func_0019f9a8(u8*);
extern "C" void func_001c0248(u8*);
extern "C" void func_00319fb0(u8*);
extern "C" u32 func_00105110(u8*);

u32 func_00320198(u8* object) {
    *(u32*)object = (u32)(long)&D_0034ee08;
    func_0019f9a8(object + 2568);
    func_001c0248(object + 2640);
    func_00319fb0(object);
    return func_00105110(object);
}
