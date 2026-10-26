#include "../common/types.h"

extern "C" u64 func_001050c8();
typedef void (*CleanupCallback)(u32*, u64, u32);

void func_0016c358(u8* object) {
    if (*(u32*)(object + 0x8b0)) {
        u64 key = func_001050c8();
        u32* receiver = *(u32**)(object + 0x8b0);
        ((CleanupCallback*)*receiver)[10](receiver, key, *(u32*)(object + 0x670));
        *(u32*)(object + 0x8b0) = 0;
    }
}
