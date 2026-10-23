#include "../common/types.h"
extern "C" u32 func_00158f90(...);

void func_00195c58(s32 unused, u8* object) {
    if ((*reinterpret_cast<u32*>(object + 0x588) & 0x80) != 0) {
        func_00158f90();
        return;
    }
    return;
}
