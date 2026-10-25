#include "../common/types.h"
extern "C" void func_002feee8(u8*,u8*);
extern "C" s32 func_002ff3fc(...);
extern "C" u8 D_01dadbd8[];
extern "C" u8 D_00371370[];
extern "C" u8 D_00371378[];
extern "C" u8 D_00371380[];

u8* func_002330c8(u8* path, u8* name) {
    s8 buffer[48];
    D_01dadbd8[0] = 0;
    func_002feee8(D_01dadbd8, D_00371370);
    s32 index = 0;
    s8* cursor;
    s8* out;
    s8 value;
    do {
        cursor = (s8*)path + index;
        out = buffer + index;
        value = *cursor;
        index++;
        *out = value;
    } while (value != '/');
    *out = 0;
    u8* pointer = D_01dadbd8;
    func_002feee8(pointer, (u8*)buffer + 4);
    func_002feee8(pointer, D_00371378);
    func_002feee8(pointer, name);
    func_002feee8(pointer, (u8*)cursor);
    func_002feee8(pointer, D_00371380);
    func_002ff3fc(pointer);
    func_002ff3fc(buffer);
    return pointer;
}
