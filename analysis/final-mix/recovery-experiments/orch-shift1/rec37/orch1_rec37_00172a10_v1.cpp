#include "../common/types.h"
struct Inner {
    u32 pad0;
    u32 target;
};
struct Holder {
    Inner* inner;
    s32 first;
    s32 second;
};
extern "C" bool func_0019ba60(...);
extern "C" void func_0016c018(u32, s32, s32);

void func_00172a10(Holder* holder) {
    Inner* inner = holder->inner;
    if (inner != 0) {
        func_0019ba60(inner->target);
        inner = holder->inner;
    }
    func_0016c018(inner->target, holder->first, holder->second);
}