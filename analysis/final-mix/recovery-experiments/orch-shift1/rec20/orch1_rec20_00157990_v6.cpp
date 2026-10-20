#include "../common/types.h"
extern "C" void func_00138c10(u8*, s32);

void func_00157990(u8* object) {
    u8* self = object;
    s32* source = *(s32**)(*(u8**)(object + 0x34) + 0x48c);
    s32 current = *(s32*)(object + 0x28);
    s32 target = *source;
    if (current != target) {
        *(s32*)(object + 0x24) = current;
        if (current < target) {
            *(s32*)(object + 0x24) = target;
        }
        *(s32*)(self + 0x28) = target;
        func_00138c10(self + 0x1d68, 0x7e);
        func_00138c10(self + 0x223c, 0x7f);
    }
}