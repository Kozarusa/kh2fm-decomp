#include "../common/types.h"
extern "C" u32 func_00139d78(...);
s32 func_0028ac98(s16*p,s32 i);
s32 func_0028ae28(u8* object,s32 index) {
    s32 offset=index*4;
    func_00139d78(*(s32*)(offset+*(s32*)(object+40)));
    s32 result=func_0028ac98((s16*)object,index);
    s32 value=*(s16*)(result+4);
    return *(s32*)(*(s32*)(offset+*(s32*)(object+40))+388)==value;
}
