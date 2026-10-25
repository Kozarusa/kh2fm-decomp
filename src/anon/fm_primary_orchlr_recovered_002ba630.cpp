#include "../common/types.h"
extern "C" u8 D_01e2a410[];
// why: the accepted C++ definition s32 func_002baf48(s32,s32,s32,s32,s32,s32) fails the isolated probe link (v1) because the probe linker script defines only the plain symbol
extern "C" s32 func_002baf48(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" u32 func_002bce10(void*, s32);
// why: no recovered call site uses this callee; a0 is the table, a1/a2 pass the target's first and third words, a3/t0 pass two output slot addresses
extern "C" void func_002bcc60(void* table, s32 first, s32 third, s32* handle, s32* result);

s32 func_002ba630(s32 first, s32 second, s32 third, s32 fourth)
{
    s32 handle = -1;
    s32 result = -1;
    func_002bcc60(D_01e2a410, first, third, &handle, &result);
    func_002baf48(handle, 0, first, second, 0, 0);
    if (third != 0) {
        func_002baf48(handle, 1, third, fourth, 0, 0);
    }
    func_002bce10(D_01e2a410, handle);
    return result;
}
