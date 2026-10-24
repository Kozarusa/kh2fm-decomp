#include "../common/types.h"
struct Cursor {
    s32 current;
    u32 value;
};
extern "C" s32 func_001b9bc8(s32);
extern "C" u32 func_0019bc38(u32);
extern "C" u8* func_0016bba8(...);

u8* func_00190730(Cursor* cursor, u8* element) {
    if (cursor->current == 0) {
        element = 0;
        cursor->current = func_001b9bc8(0);
    }
    while (cursor->current != 0) {
        if (func_0019bc38(cursor->current) != 0) {
            while ((element = func_0016bba8(cursor->current, 3, element)) != 0) {
                if (!(element[2] & 1)) {
                    cursor->value = element[0];
                    return element;
                }
            }
        }
        element = 0;
        cursor->current = func_001b9bc8(cursor->current);
    }
    return 0;
}
