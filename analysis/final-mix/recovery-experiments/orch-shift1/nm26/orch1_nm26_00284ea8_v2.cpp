#include "../common/types.h"
extern "C" u32 func_002bd7d8();
extern "C" u32 func_00103580();
extern "C" u32 D_0035f2c0;
typedef u32 (*Release)(u32,u32);
u32 func_00284ea8() {
    func_002bd7d8();
    u32 object = func_00103580();
    u32 table = *(u32*)object;
    Release callback = *(Release*)(table+4);
    u32 result = callback(object,D_0035f2c0);
    D_0035f2c0 = 0;
    return result;
}
