#include "../common/types.h"
typedef void (*Handler)(u8*, u32, u32, u32);
extern "C" u8* func_00192388(u8* text);
extern "C" s32 func_00192440(u8* text, s32 mode);
extern "C" u32 func_00192498(u8* text, u32 index);

void func_001aa558(u8* object) {
    u8* text = *(u8**)(object + 12);
    if (text == 0) {
        return;
    }
    do {
        if (func_00192440(text, 0) != 0) {
            switch (*text) {
            case 0:
            case 16:
                text = 0;
                break;
            case 5:
                if (*(u8**)(object + 24) != 0) {
                    u32 first = func_00192498(text, 1);
                    u32 second = func_00192498(text, 3);
                    u32 third = func_00192498(text, 5);
                    u8* listener = *(u8**)(object + 24);
                    Handler* table = *(Handler**)listener;
                    table[7](listener, first, second, third);
                }
                break;
            }
        }
        if (text == 0) {
            return;
        }
        text = func_00192388(text);
    } while (text != 0);
}
