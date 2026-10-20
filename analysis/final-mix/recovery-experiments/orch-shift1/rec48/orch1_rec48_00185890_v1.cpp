#include "../common/types.h"
extern "C" u32 D_01c60888;
extern "C" u32 func_001a80c8(...);

u32 func_00185890(s32 index, s32 object) {
    if (index == 0) {
        return 0;
    }
    if (object == 0) {
        return 0;
    }
    if (*(u32*)(index * 4 + D_01c60888) == 0) {
        return 0;
    }
    u32 info = func_001a80c8(object);
    return *(u32*)(*(u16*)(info + 4) * 4 + D_01c60888 + *(u32*)(index * 4 + D_01c60888) * 4);
}
