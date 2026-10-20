#include "../common/types.h"
extern "C" u8* func_001b9bc8(u8*);

void func_00185da8(u8* object) {
    do {
        object = func_001b9bc8(object);
        if (object == 0) {
            return;
        }
    } while ((*(u32*)(object + 0x588) & 0x10) == 0);
}
