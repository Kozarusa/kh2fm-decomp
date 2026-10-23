#include "../common/types.h"
extern "C" u8 D_0034af40[];
extern "C" u8 D_0034b0e0[];
extern "C" void func_00236788(u8*);
extern "C" u32 func_00239d30(u8*, s32);
extern "C" s32 func_00239d10(u8*);
extern "C" u8* func_0014aba8();
extern "C" void func_0014aa58(u8*, s32, s32);
extern "C" void func_0013f020();
extern "C" void func_0023acd8(u8*);
extern "C" void func_0023ade0(u8*);

s32 func_0015d440() {
    func_00236788(D_0034af40);
    register u8* sequence asm("$16") = D_0034b0e0; // why: original materializes the object address directly in s0
    if ((func_00239d30(sequence, *(s32*)(sequence + 276)) & 0xff) == 0 && func_00239d10(sequence) == 0) {
        func_0014aa58(func_0014aba8(), 1, 0);
        func_0013f020();
        return 1;
    }
    sequence = D_0034b0e0;
    func_0023acd8(sequence);
    *(s32*)(sequence + 328) = 0;
    *(s32*)(sequence + 332) = 0;
    func_0023ade0(sequence);
    return 0;
}
