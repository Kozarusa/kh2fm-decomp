#include "../common/types.h"
extern "C" void func_00195858(u8*, s32);

s32 func_002ece48(u8* owner, u8* object) {
    func_00195858(object + 272, 63);
    typedef s32 (*Method)(u8*, u8*);
    // why: original calls through t7 after loading the vtable into t6
    register Method method asm("$15") = *(Method*)(*(u8**)owner + 36);
    return method(owner, object);
}
