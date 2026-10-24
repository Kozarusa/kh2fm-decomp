#include "../common/types.h"

struct Request {
    s32 type;
    void* object;
};

extern "C" u8 D_0036d8b0[];
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" s32 func_00168b88(s32,u32,s32,s32);
extern "C" u32 func_0016e920(...);
extern "C" u32 func_002fee78(...);

s32 func_001af7c0(Request* request, u32 chara) {
    u8* data = (u8*)func_0016e920(chara);
    s32 mode = 0;
    switch (request->type) {
    case 0:
        mode = 0xfc;
        break;
    case 1:
    case 3:
        mode = 0xfd;
        break;
    }
    s32* item = (s32*)func_00168b38(request->object, 0xffffffff, mode);
    s32 valid = 0;
    if (item != 0) valid = item[2] != 0;
    if ((u8)valid == 0) return 0;
    s8 buffer[4];
    s32 handle = item[2];
    func_002fee78(buffer, D_0036d8b0, data[7]);
    item = (s32*)func_00168b88(handle, 0xffffffff,
                               (s32)((u32)buffer[0] | ((u32)buffer[1] << 8) | ((u32)buffer[2] << 16) | ((u32)buffer[3] << 24)), 2);
    valid = 0;
    if (item != 0) valid = item[2] != 0;
    if ((u8)valid == 0) return 0;
    return ((s32*)func_00168b38((void*)item[2], 9, 0))[2];
}
