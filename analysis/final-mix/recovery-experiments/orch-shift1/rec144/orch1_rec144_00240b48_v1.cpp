#include "../common/types.h"
extern "C" u8* D_0035ec90;
extern "C" u32 func_001058e8(void);
extern "C" u32 func_002fdd68(...);
u32 func_00240b48(u8* object) {
    if (!object) object = D_0035ec90;
    u32 result = func_001058e8();
    return func_002fdd68(result, object, 0x10fc0);
}
