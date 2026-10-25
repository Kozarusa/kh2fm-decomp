#include "../common/types.h"
extern "C" u32 func_001bc778(...);
extern "C" u32 func_00176b20(...);
extern "C" bool func_0019ba60(...);
extern "C" u64 func_0016a070(...);
extern "C" u64 func_001b77e8(...);
extern "C" s32 func_001bc780(s32,u64,s32,u64);

s32 func_001bec68(u8* object) {
    u8* menu = object + 500;
    s32 index = 0;
    s32 result;
    func_001bc778(menu);
    do {
        u32 member = func_00176b20(index);
        index++;
        result = func_0019ba60(member);
        if (result != 0 && (*(u32*)(member + 0x588) & 0x400000) == 0 && *(s32*)(member + 0x48c) != 0) {
            *(u32*)(object + *(s32*)(menu + 8) * 4 + 0xa5c) = member;
            result = func_001bc780((s32)menu, func_001b77e8(func_0016a070(member)), 0, 1);
        }
    } while (index < 3);
    return result;
}
