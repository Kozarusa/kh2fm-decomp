#include "../common/types.h"
extern "C" u8 D_0032bae0[];
extern "C" u32 func_00198450(...);
extern "C" u32 func_0016c008(s32, s32);
// why: exact types of the accepted definition (orchcu 001d9dd0), C linkage like its sibling callee declarations
extern "C" u8* func_001d9dd0(u32 a, u32 b, u32 c);
extern "C" u32 func_001d9d48(u8* data);
extern "C" u32 func_0016ac38(...);

s32 func_001d9f30(u8* object) {
    // why: original forms the D_0032bae0 base in s0/s1 before the first call (v1 rematerialized it after)
    u8* pair = D_0032bae0;
    func_00198450(object);
    u32 unit = func_0016c008((s32)object, 1);
    u8* entry = func_001d9dd0(pair[0], pair[1], unit);
    *(u8**)(object + 0x9f8) = entry;
    if (entry == 0 || func_001d9d48(entry) == 0) {
        s32 result = func_0016ac38(object, 0, 1, 0, 0);
        *(s32*)(object + 0x9f4) = result;
        return result;
    }
    // why: original loads the method pointer into t6 ($14) before jalr
    register s32 (*method)(u8*) asm("$14") = *(s32 (**)(u8*))(*(u8**)object + 0x20);
    return method(object);
}
