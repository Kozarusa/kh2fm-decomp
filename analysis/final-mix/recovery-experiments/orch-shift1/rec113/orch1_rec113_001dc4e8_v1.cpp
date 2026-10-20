#include "../common/types.h"
extern "C" u32 func_001dc018(u32, u32, u8*, u8*);

bool func_001dc4e8(u8* object, u32 first, u32 second, u32 value) {
    u32 found = func_001dc018(first, second, object + 0x14, object + 0x18);
    if (found != 0) {
        *(u32*)(object + 0x10) = value;
    }
    return found != 0;
}
