#include "../common/types.h"
extern "C" u8 D_0032f054;
extern "C" u32 func_001050d8(u64);
extern "C" void func_001b0330(u32);
extern "C" void func_001b6298(u32, u8*, u32, u32);

void func_001b6c60(u8* object) {
    func_001b0330(*(u32*)(object + 2488));
    D_0032f054 = 0;
    u32 block = func_001050d8(32);
    func_001b6298(block, object, 0, 0);
}
