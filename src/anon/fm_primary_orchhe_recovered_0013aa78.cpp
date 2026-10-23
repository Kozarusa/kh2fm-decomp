#include "../common/types.h"
extern "C" u32 func_00138d60(...);
extern "C" u64 func_00139620(...);
extern "C" u32 func_00239988(...);
extern "C" u64 func_0013ac60(...);

u64 func_0013aa78(u8* object, s32 image, s32 first, s32 second, s32 stock, s32 mode, s32 kind) {
    func_00138d60(object, 5303, first, second, image, 0, mode);
    *(s32*)(object + 412) = 10;
    *(s32*)(object + 416) = -7;
    *(s32*)(object + 424) = 14;
    *(s32*)(object + 428) = 1;
    func_00139620(object);
    func_00239988(object + 436, first, second);
    return func_0013ac60(object, kind, stock);
}
