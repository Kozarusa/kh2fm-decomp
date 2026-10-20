#include "../common/types.h"
extern "C" void func_00138c10(u8*, s32);

void func_00157990(u8* object) {
    s32 current = *(s32*)(object + 0x28);
    s32 target = **(s32**)(*(u8**)(*(u8**)(object + 0x34) + 0x48c) + 0);
    if (current != target) {
        if (current < target) {
            *(s32*)(object + 0x24) = target;
        } else {
            *(s32*)(object + 0x24) = current;
        }
        *(s32*)(object + 0x28) = target;
        func_00138c10(object + 0x1d68, 0x7e);
        func_00138c10(object + 0x223c, 0x7f);
    }
}