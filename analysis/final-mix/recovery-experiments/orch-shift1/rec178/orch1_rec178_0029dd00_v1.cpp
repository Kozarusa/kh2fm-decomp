#include "../common/types.h"
extern "C" s8* D_0035f5ac;
extern "C" u32 D_0035f5c8;
extern "C" u32 D_0035f5cc;
extern "C" u32 func_00293de8(s32);
extern "C" void func_00293cb8(u8*,s32,u32);
extern "C" u32 func_002ff918(u8*,u32);
extern "C" u32 func_002ff2e8(...);
extern "C" u32 func_002931a8(u8*);
u32 func_0029dd00() {
    u8 buffer[128];
    func_00293cb8(buffer,4,func_00293de8(D_0035f5ac[4]));
    u32 result=func_002ff918(buffer,D_0035f5c8);
    if(result) func_002ff2e8(result,D_0035f5cc);
    return func_002931a8(buffer);
}
