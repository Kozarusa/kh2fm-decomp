#include "../common/types.h"

extern "C" u8* D_00365c48;
extern "C" void func_00302e10(u8*);
extern "C" u64 func_002ffd78(...);

u64 func_002ffd00(u8* object, u64 value, u64 mode) {
    u8* context = *(u8**)(object + 0x54);
    if (context == 0) {
        u8* fallback = D_00365c48;
        *(u8**)(object + 0x54) = fallback;
        context = fallback;
    }
    if (*(u32*)(context + 0x38) == 0) {
        func_00302e10(context);
    }
    return func_002ffd78(*(u8**)(object + 0x54), object, value, mode);
}
