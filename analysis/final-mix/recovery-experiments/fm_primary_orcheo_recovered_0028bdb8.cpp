#include "../common/types.h"
extern "C" u32 func_0028be58(...);
extern "C" u32 func_0028e4c8(s32,s32);
extern "C" u32 func_0028e560(u64,void*,s32,u64);

u32 func_0028bdb8(u8* object) {
    // why: retain outgoing callee result in original v0 register.
    register u32 result asm("$2") = func_0028be58(object);
    if (result != 0) {
        result = func_0028e4c8(*(s32*)object,0);
        if (result != (u32)*(s16*)(object+16)) {
            return func_0028e560(*(s32*)object,object+16,4,(u64)-1);
        } else {
            goto done;
        }
    } else {
        goto done;
    }
done:
    asm("" : "+r"(result)); // why: preserve original outgoing v0 at shared exit.
    return result;
}
