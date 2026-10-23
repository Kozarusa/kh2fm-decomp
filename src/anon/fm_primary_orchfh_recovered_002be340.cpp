#include "../common/types.h"
extern "C" u8 D_002be3a8[];
extern "C" u8 D_002be3c8[];
extern "C" u8 D_002be428[];
extern "C" u32 func_00102c18(u32,u32,u32);
extern "C" u32 func_00102c48(u32, u32, u32, u32);
extern "C" u32 func_001050d8(u64);
extern "C" void func_002bd998(u32, u32);

u32 func_002be340(u32 object) {
    u32 block = func_001050d8(108);
    func_002bd998(block, object);
    u32 task = func_00102c48(1, 15000, (u32)D_002be3a8, 8192);
    *(u32*)(task + 0x30) = (u32)D_002be3c8;
    return func_00102c18(1, 0xee48, (u32)D_002be428);
}
