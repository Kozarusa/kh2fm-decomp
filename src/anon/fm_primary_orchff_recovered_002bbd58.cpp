#include "../common/types.h"
extern "C" u32 func_002bb9b8(...);
extern "C" u32 func_002bbbc8(...);
extern "C" u32 func_002bbc90(...);

u32 func_002bbd58(u8* object) {
    u32 result;
    switch (object[0x31]) {
    case 5:
        return func_002bbbc8(object);
    case 6:
        return func_002bbc90(object);
    default:
        result = func_002bb9b8(object);
        asm("" : "+r"(result)); // why: keeps default call non-tail, original uses jal then returns
        return result;
    }
}
