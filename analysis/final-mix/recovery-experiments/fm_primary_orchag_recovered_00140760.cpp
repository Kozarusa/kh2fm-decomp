#include "../common/types.h"
struct Target {
    s32 (**vtable)(Target*);
};
extern "C" void func_0013f5f0(u8*);
extern "C" u32 func_00167f18(s32);
extern "C" void func_00140618(u8*, u32);

void func_00140760(u8* object) {
    func_0013f5f0(object);
    u32 state = func_00167f18(0);
    Target* target = *(Target**)(object + 0x44);
    s32 result = ((s32 (*)(Target*))(*(u32**)target)[0x10])(target);
    if (result) {
        func_00140618(object, state);
    }
}
