#include "../common/types.h"
extern "C" u8* func_00100430(...);
extern "C" u8* func_00100468(...);
extern "C" u8* func_001004c0(...);
extern "C" s32 func_002ff3fc(...);

u8 func_001009a0(u8* object) {
    u8 buffer[24];
    u8* string = object + 9;
    if (string[0] != 'z') {
        return 0;
    }
    u8* pointer = string + func_002ff3fc(string) + 1;
    pointer = func_00100430(pointer, buffer);
    pointer = func_00100468(pointer, buffer + 8);
    pointer++;
    string++;
    pointer = func_00100430(pointer, buffer);
    while (1) {
        if (*string == 'R') {
            return *pointer;
        } else if (*string == 'P') {
            pointer = func_001004c0((u8)(*pointer & 0x7f), 0, pointer + 1, buffer + 16);
        } else if (*string == 'L') {
            pointer++;
        } else {
            return 0;
        }
        string++;
    }
}
