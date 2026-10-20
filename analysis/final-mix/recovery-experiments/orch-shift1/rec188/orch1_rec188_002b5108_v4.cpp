#include "../common/types.h"
extern "C" u32 D_0035f654;
extern "C" u32 D_0035f6c8;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_002b6338(u32);

u32 func_002b5108(u32 value, s32 index) {
    register u32 result asm("$2"); // why: both branch results follow original v0 transport
    func_00139d78(D_0035f654);
    u32 repeated_value = value;
    if (index >= 0) {
        func_002b6338(D_0035f6c8);
        *(u32*)(D_0035f654 + 0x198) = D_0035f6c8;
        asm("" : "=r"(result)); // why: outgoing callee result remains in v0
        return result;
    }
    result = func_00192048(value, 0x200, repeated_value, index);
    *(u32*)(D_0035f654 + 0x198) = result;
    return result;
}
