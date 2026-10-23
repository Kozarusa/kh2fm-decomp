#include "../common/types.h"
extern "C" u32 func_00105110(u32*);
extern "C" void func_002d2a08(u32);
extern "C" void func_002e7328(u32);
extern "C" u8 D_003621a0[];

u32 func_002d4828(u32 object) {
    *(u32*)object = (u32)D_003621a0;
    func_002e7328(object + 3208);
    func_002d2a08(object);
    return func_00105110((u32*)object);
}
