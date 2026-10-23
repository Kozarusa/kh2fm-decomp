#include "../common/types.h"
extern "C" s32 func_002f6020(u32);
extern "C" s32 func_002f5f50(u32, u8*);
extern "C" s32 func_002f5e78(u32, u8*);
extern "C" u32 func_00105c30(void);
extern "C" u32 func_00242bd0(void);
extern "C" u64 func_00167778(u8*, u8*);
extern "C" u32 func_00242a00(void);
extern "C" void func_00167ad0(u8*, u32);
extern "C" u32 func_001676b0(void*, u64);
extern "C" u32 func_00167658(void*, u64);

u32 func_001678f0(u8* object) {
    u8 data[256];
    s32 done = 0;
    u64 buttons = 0;
    u32 result;
    s32 status = func_002f6020(*(u32*)(object + 76));
    *(u32*)(object + 80) = status != 0;
    if (status != 1) goto finish;
    if (*(s32*)(object + 72) == 0) {
        if (func_002f5f50(*(u32*)(object + 76), object + 84) < 0) goto finish;
    }
    if (func_002f5e78(*(u32*)(object + 76), data) < 0) goto finish;
    {
        s32 flag = 0;
        buttons = (s32)((data[0] | (data[1] << 8)) ^ 0xffff);
        if (func_00105c30() == 1 || func_00105c30() == 8) {
            flag = 1;
        }
        if ((u8)flag) {
            if (buttons & 0x2000) buttons |= 0x1000000;
            if (buttons & 0x4000) buttons |= 0x2000000;
        } else {
            if (buttons & 0x4000) buttons |= 0x1000000;
            if (buttons & 0x2000) buttons |= 0x2000000;
        }
        u32 camera = func_00242bd0();
        if (buttons & 0x100) {
            if ((camera ^ 1) != 0) buttons |= 0x4000000;
            else buttons |= 0x8000000;
        } else {
            if (camera != 0) buttons |= 0x4000000;
            else buttons |= 0x8000000;
        }
        if ((object[86] & 0xf) == 15 && *(s32*)(object + 72) == 1) {
            buttons |= func_00167778(object, data);
        }
        u32 vibration = 0;
        if (func_00242a00()) {
            u32 high = object[69] << 1;
            vibration = ((u32)(s8)object[68] >> 31) | high;
        }
        func_00167ad0(object, vibration);
        done = 1;
    }
finish:
    if (done == 1) {
        if (*(s32*)(object + 72) != 1) *(u64*)object = buttons;
        result = func_001676b0(object, buttons);
        *(s32*)(object + 72) = done;
    } else {
        result = func_00167658(object, 0);
        *(s32*)(object + 72) = done;
    }
    object[69] = 0;
    object[68] = 0;
    return result;
}
