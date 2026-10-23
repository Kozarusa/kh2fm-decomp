#include "../common/types.h"
extern "C" void func_002cfeb0(u32,u32,u32,u32);
extern "C" u32 func_002cf280(...);
extern "C" char D_003627c8;

u32 func_002daca0(u32 object, u32 arg1, u32 arg2) {
    func_002cfeb0(object, arg1, 3, arg2);
    *(u32 *)(object + 2836) = 0;
    *(u8 *)(object + 2840) = 0;
    *(u32 *)object = (u32)(long)&D_003627c8;
    *(u32 *)(object + 2844) = 0;
    return func_002cf280(object + 2800, 1, 0);
}
