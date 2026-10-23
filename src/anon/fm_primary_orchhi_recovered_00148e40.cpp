#include "../common/types.h"

void func_00148e40(void* context, u8* node, u8** list, s32* count) {
    u32 flags = *(u32*)(node + 248);
    if (flags & 0x8) {
        goto add;
    }
    if (flags & 0x40) {
    add:
        s32 index = *count;
        ((s32*)list)[index] = (s32)node;
        *count = index + 1;
    }
    u8* child = 0;
    while ((child = (child == 0) ? *(u8**)(node + 240) : *(u8**)(child + 236)) != 0) {
        func_00148e40(context, child, list, count);
    }
}
