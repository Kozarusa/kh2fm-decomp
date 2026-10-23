#include "../common/types.h"
extern "C" u32 func_002cc620(...);

void func_002e3c28(u8** object) {
    u8* first = object[0];
    u8* second = object[1];
    u8* pointer = *(u8**)(first + 4);
    u8* other = *(u8**)(second + 4);
    if (pointer != 0) {
        u8* input = *(u8**)(pointer + 0x508);
        if (input != 0 && other != 0) {
            func_002cc620(input, pointer, other);
        }
    }
}
