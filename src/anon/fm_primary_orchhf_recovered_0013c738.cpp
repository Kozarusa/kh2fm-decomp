#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Object { Method* table; };
extern "C" u32 func_00167f18(s32);
extern "C" u32 func_0016b0d0(void);
extern "C" s32 func_0013c698(u8*);
extern "C" s32 func_0013c8b0(u8*);

s32 func_0013c738(u8* object) {
    if (object[0x2a9] == 0) {
        object[0x2a9] = 1;
        return 0;
    }
    Object* player = (Object*)func_0016b0d0();
    if (player != 0 && player->table[16](player) != 0 && *(s64*)(func_00167f18(0) + 8) != 0) {
        return 1;
    }
    if (func_0013c698(object) != 0) {
        return 1;
    }
    return func_0013c8b0(object) != 0;
}
