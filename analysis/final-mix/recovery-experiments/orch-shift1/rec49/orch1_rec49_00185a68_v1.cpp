#include "../common/types.h"

void func_00185a68(u8* object, u32 arg1, u32 arg2) {
    u8* target = *(u8**)(object + 0x9f4);
    (*(void (**)(u8*, u32, u32, u8*))(*(u8**)target + 0x50))(target, arg1, arg2, object);
}
