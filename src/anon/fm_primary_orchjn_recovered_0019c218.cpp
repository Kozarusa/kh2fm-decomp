#include "../common/types.h"
struct Info {
    u16 id;
    u8 pad02[10];
    s32 flags;
    u8 pad10[18];
    u16 other;
};
struct Actor {
    u8 pad000[320];
    u32 link;
    u8 pad144[28];
    u32 state;
    u32 pad164;
    u32 extra;
    u8 pad16c[928];
    u32 target;
    u8 pad510[1184];
    f32 value;
};
extern "C" bool func_001917c0(void);
extern "C" u32 func_0019c090(...);

s32 func_0019c218(Actor* actor, Info* info) {
    if ((info->flags & 2) && func_0019c090(actor)) {
        return 0;
    }
    u32 state = actor->state;
    if (state & 0x20000) {
        if (actor->target == info->id) {
            return 1;
        }
    }
    if (info->other != 0 && (state & 0x200000)) {
        if (actor->target == info->other) {
            return 1;
        }
    }
    if (state & 0x40000000) {
        return 0;
    }
    if ((info->flags >> 4) & 1) {
    } else {
        if (func_001917c0()) {
            return 0;
        }
    }
    s32 flags = info->flags;
    if ((flags >> 8) & 1) {
        if (actor->state & 0x80000) {
            return 1;
        }
    }
    s32 result = 0;
    u32 current;
    s32 any;
    if (actor->value <= 0.0f) {
        if (actor->link == 0) {
            goto one;
        }
        current = actor->state;
        any = 0;
        if (current & 4) {
            goto set;
        }
        if (current & 8) {
            goto set;
        }
        if (current & 0x10) {
        set:
            any = 1;
        }
        if ((u8)any) {
            goto one;
        }
        if ((flags >> 7) & 1) {
        } else {
            if (current & 0x400) {
                goto one;
            }
            if (actor->extra & 0x20) {
                goto one;
            }
        }
        if (flags & 4) {
        one:
            result = 1;
        }
    }
    return result;
}
