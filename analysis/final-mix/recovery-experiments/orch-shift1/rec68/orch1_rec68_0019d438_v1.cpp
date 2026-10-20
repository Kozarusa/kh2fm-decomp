#include "../common/types.h"
extern "C" s32 func_0019d4a8(u8*);
extern "C" u32 func_0015a638(u8*, u8*);
extern "C" u32 func_002c0688(u32, u8*);

u32 func_0019d438(u8* object) {
    if (func_0019d4a8(object) != 0) {
        return func_002c0688(*(u32*)(object + 40), object + 4);
    }
    return func_0015a638(object + 4, object + 4);
}
