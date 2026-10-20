#include "../common/types.h"
extern "C" s32 D_0034dca0;
extern "C" s32 D_0034dca4;
extern "C" void func_0016fb00(s32);

void func_001700e8(s32 object) {
    s32 previous;
    if (object == D_0034dca0) {
        D_0034dca0 = *(s32*)(object + 0x3c);
        previous = 0;
    } else {
        s32 next = *(s32*)(D_0034dca0 + 0x3c);
        previous = D_0034dca0;
        while (next != object) {
            previous = next;
            next = *(s32*)(next + 0x3c);
        }
        *(s32*)(previous + 0x3c) = *(s32*)(object + 0x3c);
    }
    if (object == D_0034dca4) {
        D_0034dca4 = previous;
    }
    *(s32*)(object + 0x3c) = 0;
    func_0016fb00(object);
}