#include "../common/types.h"
extern "C" u32 func_001dc018(u32, u32, u8*, u8*);

bool func_001dc4e8(u8* object, u32 first, u32 second, u32 value) {
    bool result = false;
    if (func_001dc018(first, second, object + 0x14, object + 0x18) != 0) {
        *(u32*)(object + 0x10) = value;
        result = true;
    }
    return result;
}
