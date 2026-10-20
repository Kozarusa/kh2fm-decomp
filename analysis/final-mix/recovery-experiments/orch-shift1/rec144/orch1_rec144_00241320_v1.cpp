#include "../common/types.h"
extern "C" u8* D_0035ec98;
extern "C" u32 func_002fde18(...);
u32 func_00241320() {
    u8* object = D_0035ec98;
    return func_002fde18(object + *(s32*)(object + 4) * 40 + 8, 0, 40);
}
