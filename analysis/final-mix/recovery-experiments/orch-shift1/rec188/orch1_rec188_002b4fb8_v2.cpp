#include "../common/types.h"
extern "C" u32 D_0035f654;
extern "C" u32 D_0035f650;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);

u32 func_002b4fb8() {
    u32 result = 0;
    if (D_0035f654 != 0) {
        result = func_00139d78(D_0035f654);
    }
    if (result != 0) {
        func_0028acc8(D_0035f650);
        register u32 call_result asm("$2"); // why: outgoing callee result remains in v0
        asm("" : "=r"(call_result));
        return call_result;
    }
    return result;
}
