#include "../common/types.h"
extern "C" u8 D_00348700;
extern "C" u32 D_0032b96c;
extern "C" void D_0013ef90();
extern "C" u32 func_00102788(u64, u64, u64, u64);

u32 func_0013efe8() {
    D_00348700 = 0;
    return func_00102788(D_0032b96c, 0, 300000, (u32)&D_0013ef90);
}