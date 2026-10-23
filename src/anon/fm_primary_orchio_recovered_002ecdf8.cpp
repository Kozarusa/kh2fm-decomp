// func_002ecdf8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" void func_00195858(u8*, s32);

s32 func_002ecdf8(u8* owner, u8* object) {
    func_00195858(object + 272, 0x3c);
    typedef s32 (*Method)(u8*, u8*);
    // why: original calls through t7 after loading the vtable into t6
    register Method method asm("$15") = *(Method*)(*(u8**)owner + 36);
    return method(owner, object);
}
