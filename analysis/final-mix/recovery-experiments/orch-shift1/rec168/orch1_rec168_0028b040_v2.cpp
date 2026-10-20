#include "../common/types.h"
s32 func_0028b040(s16* object) {
    s32 count=object[11];
    if(count!=0) return (object[0]+object[9])%count;
    return object[0]+object[9];
}

