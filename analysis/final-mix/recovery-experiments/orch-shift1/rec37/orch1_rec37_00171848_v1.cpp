#include "../common/types.h"
struct Target {
    u8 pad0[0x588];
    u32 flags;
};
struct Inner {
    u32 pad0;
    Target* target;
};
struct Holder {
    Inner* inner;
};
extern "C" bool func_0019ba60(...);
extern "C" void func_00177998();

void func_00171848(Holder* holder) {
    Inner* inner = holder->inner;
    if (inner != 0) {
        func_0019ba60(inner->target);
        inner = holder->inner;
    }
    if ((inner->target->flags & 4) != 0) {
        func_00177998();
    }
}