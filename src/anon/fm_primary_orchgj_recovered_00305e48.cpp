#include "../common/types.h"

extern "C" u32 func_00316d08(void);

u32 func_00305e48(void) {
    register u32* pointer asm("$2") = (u32*)func_00316d08(); // why: retain callee result in v0 until the original store
    register u32 value asm("$3") = 5; // why: keep the original constant in v1
    *pointer = value;
    return 0xffffffff;
}
