#include "../common/types.h"
typedef void (*Method)(s32);
extern "C" s32 D_0035dcfc;
// why: copied from the recovered call site in fm_primary_orchjb_recovered_001b5cf8.cpp, which uses the result
extern "C" u32 func_001ba028(...);
// why: matches the accepted void definition in fm_primary_orchjh_recovered_00232db0.cpp; extern "C" because the isolated probe linker script defines only the plain symbol (v1 C++ declaration failed to link)
extern "C" void func_00232db0(s32 value);

void func_0022d440() {
    if (D_0035dcfc == 0) {
        return;
    }
    s32 offset = 0;
    s32 count = 95;
    do {
        s32 object = *(s32*)(offset + D_0035dcfc + 8);
        if (object != 0) {
            func_001ba028(object);
            s32 self = *(s32*)(offset + D_0035dcfc + 8);
            (*(Method*)(*(s32*)self + 40))(self);
            *(s32*)(offset + D_0035dcfc + 8) = 0;
            func_00232db0(*(s32*)(offset + D_0035dcfc + 4));
        }
        count--;
        offset += 40;
    } while (count >= 0);
}
