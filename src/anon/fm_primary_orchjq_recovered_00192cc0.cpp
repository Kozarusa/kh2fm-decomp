#include "../common/types.h"
extern "C" s32 func_00301550(s8*, const s8*, __builtin_va_list);

s8* func_00192cc0(s8* buffer, const s8* format, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, format);
    s32 length = func_00301550(buffer, format, args);
    for (s32 index = 0; index < length; index++) {
        s8 value = buffer[index];
        if ((u32)(value - '0') < 10) {
            value = value - 15;
        } else if ((u32)(value - 'A') < 26) {
            value = value - 19;
        } else {
            switch ((u8)(value - ' ')) {
            case 0:
                value = 1;
                break;
            case 1:
                value = 'H';
                break;
            case 2:
                value = 'a';
                break;
            default:
                value = 127;
                break;
            case 5:
                value = 'J';
                break;
            case 7:
                value = 'W';
                break;
            case 10:
                value = '-';
                break;
            case 11:
                value = '+';
                break;
            case 13:
                value = ',';
                break;
            case 14:
                value = 'O';
                break;
            case 15:
                value = 'K';
                break;
            case 26:
                value = 'R';
                break;
            case 31:
                value = 'I';
                break;
            }
        }
        buffer[index] = value;
    }
    buffer[length] = 0;
    __builtin_va_end(args);
    return buffer;
}
