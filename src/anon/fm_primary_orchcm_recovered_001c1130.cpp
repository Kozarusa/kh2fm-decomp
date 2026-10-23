#include "../common/types.h"
struct __attribute__((packed)) Pair { u64 first; u64 second; };
extern "C" u8 D_01d49388[];
extern "C" u8* func_001c10f8();

u8* func_001c1130() {
    u8* source = func_001c10f8();
    Pair* from = (Pair*)source;
    Pair* to = (Pair*)(D_01d49388 + (u32)source[0x24] * 64);
    do {
        *to = *from;
        from++;
        to++;
    } while (from != (Pair*)(source + 64));
    return D_01d49388 + (u32)source[0x24] * 64;
}
