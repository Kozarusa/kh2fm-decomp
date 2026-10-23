#include "../common/types.h"
extern "C" void func_00138c10(u8*, s32);
extern "C" void func_00138c40(u8*, s32, s32);
extern "C" u8* func_0013d7f0();
extern "C" s32 func_0013dda0(s32);
extern "C" s32 func_00154ee8(u8*);
extern "C" s32 func_0023aa98(u8*);

void func_00155568(u8* object) {
    if (object[32] == 0) {
        return;
    }
    s32 mode = *(s32*)(object + 48);
    if (mode != 1) {
        return;
    }
    u8* friendObj = func_0013d7f0();
    if (friendObj[5536] == 0) {
        return;
    }
    friendObj[5536] = 0;
    s32 result = func_0013dda0(1);
    u8 flag = object[5537];
    if (result == 0) {
        if (flag != 0) {
            return;
        }
        u8* sprite = object + 916;
        func_00138c10(sprite, 73);
        *(s32*)(sprite + 392) = func_00154ee8(object);
        func_0023aa98(object + 940);
        func_00138c40(sprite, 0, 0);
        object[5537] = mode;
    } else {
        if (flag != mode) {
            return;
        }
        u8* sprite = object + 916;
        func_00138c10(sprite, 74);
        *(s32*)(sprite + 392) = func_00154ee8(object);
        s32 value = func_0023aa98(object + 940);
        func_00138c40(sprite, 0, value);
        object[5537] = 0;
    }
}
