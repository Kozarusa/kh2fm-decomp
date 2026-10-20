#include "../common/types.h"
extern "C" u32 func_001b9bc8(u32);

void func_00186078(u32 object) {
    for (;;) {
        u32 next = func_001b9bc8(object);
        if (next == 0) {
            return;
        }
        object = next;
        if ((*(u32*)(next + 1416) & 2) != 0) {
            return;
        }
    }
}
