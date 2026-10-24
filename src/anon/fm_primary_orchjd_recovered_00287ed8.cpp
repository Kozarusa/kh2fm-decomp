#include "../common/types.h"
extern "C" s32 D_0035f324;
extern "C" s32 func_001063c0(u32, u32);
extern "C" void func_00167658(u8*, s32);
extern "C" void func_00288018(void);

void func_00287ed8(u32 value) {
    if (D_0035f324 == 0) {
        s32 data = func_001063c0(80, value);
        func_00167658((u8*)data, 0);
        D_0035f324 = data;
    }
    func_00288018();
}
