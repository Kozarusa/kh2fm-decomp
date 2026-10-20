#include "../common/types.h"
extern "C" u32 func_001b9bc8(u32);

void func_00186078(u32 object) {
    do {
        object = func_001b9bc8(object);
        if (object == 0) {
            return;
        }
    } while ((*(u32*)(object + 1416) & 2) == 0);
}
