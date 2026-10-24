#include "../common/types.h"
typedef void (*VoidMethod)(...);
extern "C" u32 func_001ba028(...);
extern "C" u32 func_0018db38(u32, u32, u32, u32);
extern "C" u32 func_0018ca10(u32);

u32 func_0018fab0(u32* object) {
    func_001ba028(*(u32*)(object[1] + 4));
    u8* owner = *(u8**)(object[1] + 4);
    u32 result = func_0018db38(object[0], (u32)owner, object[2], object[3]);
    if (result != 0) {
        (*(VoidMethod*)(*(u8**)owner + 0x64))(owner, result);
        return func_0018ca10(result);
    }
    return result;
}
