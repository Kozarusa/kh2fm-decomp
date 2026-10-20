#include "../common/types.h"
extern "C" bool func_0019f060(void*);
extern "C" u32 func_00197930(u64, u64, void*);
extern "C" u32 func_0019f070(u64, u32);

u32 func_00199030(u8* object) {
    if (object[0x30] == 0) {
        s32 handle = *(s32*)(object + 0x10);
        if (handle == 0) {
            func_0019f070((u64)(u32)(object + 0x34), 0);
            return func_0019f060(object + 0x34);
        }
        func_00197930(handle, *(s32*)(object + 0x14), object + 0x34);
    }
    return 1;
}
