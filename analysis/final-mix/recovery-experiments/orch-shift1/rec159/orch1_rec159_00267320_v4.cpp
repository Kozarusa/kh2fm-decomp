#include "../common/types.h"
extern "C" s32 func_002811b0(s32,s32);
extern "C" s32 func_001a1728(s32,s32);
extern "C" s32 D_0035f010;
extern "C" s32* D_0035f0e4;
s32 func_00267320() {
    s32 index = 0;
    s32 party = func_002811b0(D_0035f010,0);
    s32 result;
    s32 more;
    do {
        s32 offset = index * 4;
        s32* pointer = (s32*)(offset + (u32)D_0035f0e4);
        result = func_001a1728(party,index);
        ++index;
        *pointer = result;
    } while ((more = index < 6));
    return result;
}



