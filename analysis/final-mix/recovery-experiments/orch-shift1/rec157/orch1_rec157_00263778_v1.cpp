#include "../common/types.h"
extern "C" s32 func_002570a0(...);
extern "C" u32 func_002632d0(...);
extern "C" bool func_001a2a50(...);
extern "C" s32 func_002811b0(s32,s32);
extern "C" s32 func_001a3458(s32,s32);
extern "C" s32 func_0013dbb0();
extern "C" s32 D_0035f010;
s32 func_00263778(s32 value) {
    s32 index = func_002570a0(10);
    u16 item = *(u16*)func_002632d0(index);
    s32 count = func_002811b0(D_0035f010,value);
    func_001a2a50(item,count,0,100);
    func_001a3458(item,100);
    return func_0013dbb0();
}
