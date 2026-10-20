#include "../common/types.h"
extern "C" u8* func_001b9bc8(u8*);

void func_00185da8(u8* object) {
    u8* next;
    do {
        next = func_001b9bc8(object);
        if (next == 0) {
            return;
        }
        object = next;
    } while ((*(u32*)(object + 0x588) & 0x10) == 0);
}
