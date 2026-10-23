#include "../common/types.h"
extern "C" u32 func_001acdc0(...);
extern "C" u64 func_001ac310(...);

void func_001ad3e0(s32* object) {
    func_001acdc0(object, object[1], object[2], object[1] + ((u32)object[23] >> 1), object[2] + ((u32)object[24] >> 1), 432);
    func_001ac310((u8*)object + 0xb6c);
}
