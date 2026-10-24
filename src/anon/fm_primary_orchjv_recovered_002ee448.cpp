#include "../common/types.h"
extern "C" u8 D_00363808[];
extern "C" u8 D_003637e0[];
extern "C" u8 D_01e2c080[];
extern "C" void func_00325840(u8*, u32*);
extern "C" void func_00106420(u32*);

// why: void under the 2026-10-20 second mixed-exit ruling: func_00325840 never writes v0, and
// the tail-called func_00106420 either returns with the caller's entry v0 untouched (null
// object) or leaves its indirect call's v0; no float is used anywhere in the chain.

void func_002ee448(u32* object) {
    *(u8**)object = D_00363808;
    func_00325840(D_01e2c080, object);
    *(u8**)object = D_003637e0;
    func_00106420(object);
}
