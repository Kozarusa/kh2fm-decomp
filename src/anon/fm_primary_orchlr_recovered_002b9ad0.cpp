#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" s32 D_003616e0;
extern "C" s32 D_01e2a400[];
extern "C" u32 func_002b7fbc(u32);
// why: the accepted C++ declaration u64 func_002b6bc4(u32) fails the isolated probe link (v1) because the probe linker script defines only the plain symbol
extern "C" u64 func_002b6bc4(u32 input);
extern "C" void func_002b9ab8(s32);
// why: no recovered call site uses this callee; a0 carries a small selector (0 or 1) and the result is discarded
extern "C" u32 func_002ba298(s32);
extern "C" u32 func_002ba390(void);
extern "C" u32 func_002bce40(s32);
extern "C" u32 func_002bce50(void*);
extern "C" u32 func_002b9b78(void);
// why: the callee only clears two globals and writes no v0, so the target has no return value
extern "C" void func_002bd218(void);

// Preserve original registry aliases.
void func_002b9ad0(void) asm("_Z16u_tail0_002b9ad0v");

void func_002b9ad0(void)
{
    func_002b7fbc(0);
    func_002b6bc4(1);
    func_002b9ab8(20);
    func_002ba298(0);
    func_002ba298(1);
    func_002ba390();
    func_002bce40((s32)D_01e2a410);
    func_002bce50(D_01e2a410);
    func_002b9b78();
    func_002bd218();
    D_003616e0 = 0;
    s32* entry = D_01e2a400;
    for (s32 count = 2; count >= 0; count--) {
        *entry++ = 0;
    }
}
