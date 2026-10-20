#include "../common/types.h"
extern "C" u32 func_002579e0();
extern "C" u32 func_0028be58(...);
extern "C" u32 func_0028be18(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" u32 D_0035f04c;
extern "C" u32 D_0035f01c;
u32 func_00269ef8() {
    func_002579e0();
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
    u32 result = func_0028acc8(D_0035f01c);
    if (result) return func_0028abe0(D_0035f01c);
    return result;
}
