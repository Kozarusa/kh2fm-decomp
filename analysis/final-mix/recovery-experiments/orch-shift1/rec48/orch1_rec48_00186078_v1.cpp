#include "../common/types.h"
extern "C" u32 func_001b9bc8(u32);

u32 func_00186078(u32 object) {
    u32 current = object;
    do {
        current = func_001b9bc8(current);
        if (current == 0) {
            return current;
        }
    } while ((*(u32*)(current + 1416) & 2) == 0);
    return current;
}
