#include "../common/types.h"
extern "C" u8* func_00192388(u8* text);
extern "C" s32 func_00192440(u8* text, s32 mode);
extern "C" u32 func_00192c40(u32 message, u8* out);
extern "C" void func_002fdd68(u8* dst, u8* src, s32 count);

u8* func_00192e50(u8* text, u8* out, s32 unused, ...) {
    __builtin_va_list args;
    __builtin_stdarg_start(args, unused);
    u8* cursor = text;
    u8* start = text;
    u8* dst = out;
    while (cursor != 0) {
        if (func_00192440(cursor, 0) != 0) {
            u32 ch = *cursor;
            s32 count;
            if (ch != 0) {
                if (ch == 13) {
                    count = cursor - start;
                    if (count > 0) {
                        func_002fdd68(dst, start, count);
                        dst += count;
                    }
                    dst += func_00192c40(__builtin_va_arg(args, u32), dst);
                    start = cursor + 1;
                }
            } else {
                count = cursor - start + 1;
                func_002fdd68(dst, start, count);
                dst += count;
            }
        }
        cursor = func_00192388(cursor);
    }
    __builtin_va_end(args);
    return out;
}
