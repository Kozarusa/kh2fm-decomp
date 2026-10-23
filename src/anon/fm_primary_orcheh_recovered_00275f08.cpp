#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00192048(u64);
extern "C" u8* D_0035f20c;

u32 func_00275f08(s64 value) {
    u32 result = func_00139d78(D_0035f20c + 1308);
    if (value < 0) {
        *(u32*)(D_0035f20c + 1716) = 0;
    } else {
        u8* object = D_0035f20c;
        result = func_00192048(value);
        u8* pointer = object + 1308;
        asm("" : "+r"(pointer)); // why: retains original intermediate object base before field store
        *(u32*)(pointer + 408) = result;
    }
    return result;
}
