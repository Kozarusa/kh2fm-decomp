#include "../common/types.h"

typedef void (*Call)(u32, u32);

void func_0018f218(u32* object) {
    u32 first = object[0];
    u32 argument = object[1];
    u32 child = *(u32*)(first + 4);
    u32 table = *(u32*)child;
    (*(Call*)(table + 0x68))(child, argument);
}
