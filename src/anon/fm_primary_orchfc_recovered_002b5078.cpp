#include "../common/types.h"
struct Inner {
    u8 padding[4];
    s16 value;
};
struct Outer {
    u8 padding[20];
    Inner* inner;
};
extern "C" u32 D_0035f654;
extern "C" u32 D_0035f650;
extern "C" Outer* D_0035f6cc;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028da70(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028ab20(u32);

u32 func_002b5078() {
    func_00139d78(D_0035f654);
    func_0028da70(D_0035f654, D_0035f6cc->inner->value);
    u32 result = func_0028acc8(D_0035f650);
    if (result != 0) {
        return func_0028ab20(D_0035f650);
    }
    return result;
}
