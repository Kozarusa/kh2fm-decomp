#include "../common/types.h"
extern "C" u32 D_004f63a0;
extern "C" u32 D_004f63a8;
extern "C" u32 D_004f63ac;
extern "C" u8 D_0032f054;
extern "C" u8* func_0016e920(u32);
extern "C" s32 func_0016eb48(u32, u32, u32, s32);
extern "C" s32 func_0016ef28(u32);
extern "C" u32 func_0016f6f8(...);
extern "C" u32 func_0016f770(...);
extern "C" u32 func_001d1438(u32);

// Preserve original registry aliases.
s32 func_0016ed50(u32 id, u32 kind, u32 mode) asm("_Z16wtarget_0016ed50jjjj");

s32 func_0016ed50(u32 id, u32 kind, u32 mode) {
    s32 result;
    switch (id) {
    case 0x238:
        return func_0016eb48(id, kind, 6, -1);
    case 0x236: {
        if (D_004f63a0 != 0) {
            return func_0016eb48(D_004f63a0, kind, 4, -1);
        }
        u8* data = func_0016e920(func_001d1438(0));
        result = func_0016eb48(*(u32*)data, kind, 4, 7);
        if (*(s8*)(data + 0x57) >= 7) {
            return result;
        }
        if (D_0032f054 == 0) {
            return result;
        }
        return func_0016ef28(D_0032f054);
    }
    case 0x237:
        return func_0016eb48(id, kind, 5, -1);
    case 0x319:
        return func_0016eb48(0x20000237, kind, 5, -1);
    case 0x31a:
        return func_0016eb48(0x20000238, kind, 6, -1);
    }
    if (func_0016f6f8(id) == 0 && func_0016f770(id) == 0 && mode == 30) {
        u8* data = func_0016e920(id);
        result = (s32)data;
        if (data == 0) {
            goto done;
        }
        switch (data[4]) {
        case 0:
            D_004f63a0 = id;
            mode = 4;
            break;
        case 1:
            mode = 5;
            break;
        case 19:
            mode = 7;
            break;
        }
    }
    switch (kind) {
    case 2410:
        D_004f63a8 = id;
        break;
    case 2420:
        D_004f63ac = id;
        break;
    }
    result = func_0016eb48(id, kind, mode, -1);
done:
    return result;
}
