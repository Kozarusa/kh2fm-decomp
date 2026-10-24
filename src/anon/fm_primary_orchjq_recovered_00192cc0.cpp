#include "../common/types.h"
extern "C" const void* D_0036ce14[32];
extern "C" s32 func_00301550(s8*, const s8*, __builtin_va_list);

s8* func_00192cc0(s8* buffer, const s8* format, ...) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036ce14
    static const void* targets[32] asm("fm_switch_table_00192cc0") = {
        &&space, &&bang, &&quote, &&other, &&other, &&percent, &&other, &&apostrophe,
        &&other, &&other, &&star, &&plus, &&other, &&minus, &&dot, &&slash,
        &&other, &&other, &&other, &&other, &&other, &&other, &&other, &&other,
        &&other, &&other, &&colon, &&other, &&other, &&other, &&other, &&question};
    __builtin_va_list args;
    __builtin_stdarg_start(args, format);
    s32 length = func_00301550(buffer, format, args);
    s32 index;
    for (index = 0; index < length; index++) {
        s8 value = buffer[index];
        if ((u32)(value - '0') < 10) {
            value = value - 15;
        } else if ((u32)(value - 'A') < 26) {
            value = value - 19;
        } else {
            u32 symbol = (u8)(value - ' ');
            if (symbol >= 32) goto other;
            goto *D_0036ce14[symbol];
        space:
            value = 1;
            goto store;
        bang:
            value = 'H';
            goto store;
        quote:
            value = 'a';
            goto store;
        percent:
            value = 'J';
            goto store;
        apostrophe:
            value = 'W';
            goto store;
        star:
            value = '-';
            goto store;
        plus:
            value = '+';
            goto store;
        minus:
            value = ',';
            goto store;
        dot:
            value = 'O';
            goto store;
        slash:
            value = 'K';
            goto store;
        colon:
            value = 'R';
            goto store;
        other:
            value = 127;
            goto store;
        question:
            value = 'I';
        }
    store:
        buffer[index] = value;
    }
    buffer[length] = 0;
    __builtin_va_end(args);
    return buffer;
}
