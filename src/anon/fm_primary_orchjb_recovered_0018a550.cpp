#include "../common/types.h"
extern "C" s32 func_0018a250(const u8*, const u8*);
extern "C" s32 func_0018a318(const u8*, const u8*);
extern "C" s32 func_0018a420(const u8*, const u8*);
extern "C" s32 func_0018a4d8(const u8*, const u8*);

s32 func_0018a550(const u8* first, const u8* second) {
    s32 result;
    switch (*(const s32*)first) {
    case 0:
        switch (*(const s32*)second) {
        case 0:
        case 3:
            result = func_0018a250(first, second);
            break;
        case 1:
            result = func_0018a318(first, second);
            break;
        default:
            return 0;
        }
        break;
    case 1:
        switch (*(const s32*)second) {
        case 0:
        case 3:
            result = func_0018a318(second, first);
            break;
        case 1:
            result = func_0018a420(first, second);
            break;
        default:
            return 0;
        }
        break;
    case 3:
        switch (*(const s32*)second) {
        case 0:
            result = func_0018a250(first, second);
            break;
        case 1:
            result = func_0018a318(first, second);
            break;
        case 3:
            result = func_0018a4d8(first, second);
            break;
        default:
            return 0;
        }
        break;
    default:
        return 0;
    }
    return result;
}
