#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector D_01e2c050;
extern "C" s32 func_0016c028(s32);
extern "C" void func_002cbec0(u8*, s32);
extern "C" void func_002eaf48(kn::FVector*, u8*, s32);
extern "C" u32 func_0016bd60(u64,u64);

// Preserve original registry aliases.
u32 func_002ec960(u8* object) asm("_Z16wtarget_002ec960jjjj");

u32 func_002ec960(u8* object) {
    // why: original keeps the path pointer in s0 and the object in s1
    register u8* path asm("$16") = *(u8**)(object + 1288);
    func_002cbec0(path, func_0016c028((s32)object));
    kn::FVector position;
    func_002eaf48(&position, object, 1);
    // why: a plain Quad copy folds the address and hoists the call arguments (v1, rec217 v6-v8); the original uses the kn::FVector assignment (lq/sq through t0)
    D_01e2c050 = position;
    return func_0016bd60((s32)object, 61);
}
