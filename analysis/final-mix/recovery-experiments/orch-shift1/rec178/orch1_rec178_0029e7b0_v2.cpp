#include "../common/types.h"
extern "C" s16 D_00374a08[];
s32 func_0029e7b0(s32 value) {
    s32 result=-1;
    u32 index=0;
    if(D_00374a08[0]>0) {
        do {
            if(D_00374a08[index*2]==value) return D_00374a08[index*2+1];
            ++index;
        } while(D_00374a08[index*2]>0);
    }
    return result;
}

