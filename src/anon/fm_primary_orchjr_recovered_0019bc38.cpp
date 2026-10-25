#include "../common/types.h"
struct Attach {
    u8 pad0[0x588];
    u32 flags;
};
struct Object {
    u8 pad0[0x108];
    u32 flags108;
    u8 pad10c[0x570 - 0x10c];
    Attach* attach;
    u8 pad574[0x7f8 - 0x574];
    u32 flags7f8;
};

extern "C" u32 D_0034f240;
extern "C" u8 func_0016a040(s32);
extern "C" s64 func_0016bba8(...);
extern "C" bool func_001917c0(void);
extern "C" bool func_001c0cd8(s32);

s32 func_0019bc38(Object* object) {
    s32 result;
    switch (func_0016a040((s32)object)) {
    case 0:
    case 1:
    case 5:
        goto zero;
    case 8:
    case 13:
        if (func_001917c0() && (D_0034f240 & 0x10000) != 0) {
            result = 0;
            goto done;
        }
        break;
    }
    if (func_001c0cd8((s32)object)) {
        if ((object->attach->flags & 0x80) != 0) {
            result = 0;
            goto done;
        }
    }
    result = 0;
    if ((object->flags7f8 & 0x400) == 0) {
        goto done;
    }
    if ((object->flags108 & 0x20) != 0) {
        goto done;
    }
    if (func_0016bba8(object, 3, 0) != 0) {
        result = 1;
        goto done;
    }
zero:
    result = 0;
done:
    return result;
}
