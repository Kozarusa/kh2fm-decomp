#include "../common/types.h"
typedef void (*Method)(void*);
struct Object { Method* table; };
extern "C" s32 func_0014c350(u8*);
extern "C" void func_0014c738(u8*);

s32 func_0015d828(u8* object) {
    s32 count = 5;
    u8* pointer;
    func_0014c738(object + 16);
    ((Object*)(object + 544))->table[2](object + 544);
    pointer = object;
    do {
        ((Object*)(pointer + 2608))->table[2](pointer + 2608);
        count--;
        ((Object*)(pointer + 1072))->table[2](pointer + 1072);
        pointer += 256;
    } while (count >= 0);
    return func_0014c350(object + 4144);
}
