#include "../common/types.h"
extern "C" u8* func_001c3748(u8*, u8*);
extern "C" bool func_001c3888(void*);

bool func_002c2688(u8* object, s32 index) {
    s32 count = 0;
    u8* node = 0;
    while ((node = func_001c3748(object, node)) != 0) {
        if (count == index) {
            return func_001c3888(node);
        }
        count++;
    }
    return false;
}
