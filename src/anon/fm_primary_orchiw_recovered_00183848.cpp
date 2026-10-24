#include "../common/types.h"
extern "C" u32 func_00144d10(...);
extern "C" u32 func_0019bb18(...);
extern "C" void func_001b7a18(...);
extern "C" u32 func_001b9bc8(...);
extern "C" u32 func_002cf1f8(...);

u32 func_00183848(s32 object, u64 value) {
    s32 other = 0;
    u32 last;
    s32 result;
    goto scan;
done:
    return last;
scan:
    while (last = other = func_001b9bc8(other), other != 0) {
        result = func_0019bb18(other);
        if ((((result && (*(s32*)(object + 0x570) != other)) && (*(s32*)(other + 0x570) != object)) && (other != object && ((*(s32*)(object + 0x8b0) == 0 || (*(s32*)(other + 0x8b0) == 0)) || (result = func_00144d10(object + 0x740, other + 0x740), result)))) && (result = func_002cf1f8(object, other), result)) {
            func_001b7a18(*(u32*)(object + 0x828), *(u32*)(other + 0x828), value);
        }
    }
    goto done;
}
