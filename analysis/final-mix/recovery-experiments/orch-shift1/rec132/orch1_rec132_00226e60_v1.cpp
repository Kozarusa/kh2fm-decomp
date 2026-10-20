#include "../common/types.h"
extern "C" bool func_00197920(...);
extern "C" u32 func_00226dc8(void);
extern "C" u8 D_0035de0c;
u32 func_00226e60(u8 value) {
    u32 result = func_00197920();
    if (result == 0) return result;
    D_0035de0c = value;
    return func_00226dc8();
}