#include "../common/types.h"
extern "C" u8* func_00198c28(s32, s32);
extern "C" void func_00198e40(void*, s32);
extern "C" void func_00198e48(void*, s32);
extern "C" void func_00198e50(u8*, u32, s32);
extern "C" void func_00198e60(u8*, s32, u8*);
extern "C" void func_0019ef90(u8*, u8*);

void func_00182280(u32 unused, u8* data) {
    u8* cursor = data;
    u8* end = cursor + *(s16*)(cursor + 2) * 4 + 4;
    u8* object = func_00198c28(*(s16*)(data + 4), *(s16*)(data + 6));
    cursor += 8;
    while (cursor < end) {
        switch (*(u16*)cursor) {
        case 0:
            func_00198e50(object, *(u32*)(cursor + 4), *(s16*)(cursor + 2));
            cursor += 8;
            break;
        case 1:
            func_0019ef90(object + 0x34, cursor + 4);
            cursor += 16;
            break;
        case 2:
            func_00198e40(object, *(s16*)(cursor + 2));
            cursor += 4;
            break;
        case 3:
            func_00198e48(object, *(s16*)(cursor + 2));
            cursor += 4;
            break;
        case 4:
            *(s32*)(object + 0x48) = *(s16*)(cursor + 2);
            cursor += 4;
            break;
        case 5:
            *(s32*)(object + 0x4c) = *(s16*)(cursor + 2);
            cursor += 4;
            break;
        case 6:
            func_00198e60(object, *(s16*)(cursor + 2), cursor + 4);
            cursor += *(s16*)(cursor + 2) * 4 + 4;
            break;
        case 7:
            *(s32*)(object + 0x50) = *(s16*)(cursor + 2);
            cursor += 4;
            break;
        case 8:
            *(u32*)(object + 0x54) |= 1;
            cursor += 4;
            break;
        }
    }
}
