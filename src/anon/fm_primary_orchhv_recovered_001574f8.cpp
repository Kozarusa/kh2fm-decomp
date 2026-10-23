#include "../common/types.h"
extern "C" u64 func_00138c10(...);
extern "C" u64 func_001543a0(...);
extern "C" s32 func_00155d58(...);
extern "C" u64 func_00157990(...);
extern "C" s32 func_001581a8(...);
extern "C" s32 func_002ba358(...);
extern "C" s32 func_002ba368(...);

// Preserve original registry aliases.
s32 func_001574f8(u8* object, s32 value) asm("_Z16wtarget_001574f8jjjj");

s32 func_001574f8(u8* object, s32 value) {
    s32 result;
    u8* sprite;
    func_00157990(object, value);
    sprite = object + 6704;
    func_00138c10(sprite, value);
    *(s32*)(sprite + 392) = func_00155d58(object, 0);
    func_00138c10(object + 7116, func_00155d58(object, 1));
    func_00138c10(object + 8352, func_00155d58(object, 2));
    func_001543a0(object + 64, 1, *(s32*)(object + 24));
    result = func_001581a8(object);
    if (result != 0) {
        result = func_002ba358();
        if (result == 0) {
            return func_002ba368();
        }
    }
    return result;
}
