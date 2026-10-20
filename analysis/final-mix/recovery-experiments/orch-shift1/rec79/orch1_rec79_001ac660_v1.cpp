#include "../common/types.h"
extern "C" u32 func_00105110(u64);
extern "C" u32 func_0031fe00(s32, u64);
extern "C" u8 D_00350c50[];

void func_001ac660(u32* object) {
    *object = (u32)D_00350c50;
    func_0031fe00(0x1c6ced0, (u64)object);
    func_00105110((u64)object);
}
