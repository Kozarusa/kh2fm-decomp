#include "../common/types.h"

s8* func_00132068(s8* base, s32 index) {
    s8* result = base;
    s16 tag;
    if (base == 0) goto zero;
    tag = *(s16*)base;
    if (tag == -1) goto indexed;
    if (tag == 0) goto done;
zero:
    result = 0;
done:
    return result;
indexed:
    return base + *(s32*)(base + index * 4 + 8);
}
