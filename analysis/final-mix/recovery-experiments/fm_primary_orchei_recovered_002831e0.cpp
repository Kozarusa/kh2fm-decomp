#include "../common/types.h"
extern "C" u64 func_00257708(...);
extern "C" u32 func_00283d00(s32);
extern "C" u32 func_00283f50();
extern "C" u32 func_002833f8();
extern "C" u32* D_0035f2b4;

u32 func_002831e0(s32 value,u32 flag) {
    func_00257708(1);
    *D_0035f2b4 = flag;
    func_00283d00(value);
    func_00283f50();
    return func_002833f8();
}
