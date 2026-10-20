#include "../common/types.h"
extern "C" u8* D_01c60888;
extern "C" u32 func_001a80c8(...);

u32 func_00185890(s32 index, s32 object) {
    u32 result = 0;
    if (index != 0 && object != 0 && *(u32*)(D_01c60888 + index * 4) != 0) {
        u32 info = func_001a80c8(object);
        u8* base = D_01c60888;
        u8* entry = base + *(u32*)(base + index * 4) * 4;
        result = *(u32*)(*(u16*)(info + 4) * 4 + entry);
    }
    return result;
}
