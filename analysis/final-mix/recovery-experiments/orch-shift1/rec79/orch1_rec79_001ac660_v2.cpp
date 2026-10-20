#include "../common/types.h"
extern "C" u32 func_00105110(void*);
extern "C" u32 func_0031fe00(void*, void*);
extern "C" u8 D_00350c50[];
extern "C" u8 D_01c6ced0[];

void func_001ac660(u32* object) {
    *object = (u32)D_00350c50;
    func_0031fe00(D_01c6ced0, object);
    func_00105110(object);
}
