#include "../common/types.h"
extern "C" bool func_0017a538(...);

bool func_0019bf00(u8* object) {
    if ((*(u32*)(object + 0x588) & 0x80) != 0 && func_0017a538()) {
        return true;
    }
    return (*(u32*)(object + 0x108) & 0x100000) != 0;
}
