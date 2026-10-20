#include "../common/types.h"
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(...);
extern "C" u8 func_00253918(...);
extern "C" u32 func_002539e8(...);
bool func_00259350(u32 value) {
    u32 current = func_002538f8();
    bool result = true;
    if (current == 0) {
        current = func_00253928(value);
        result = true;
        if (current == 0) {
            current = func_00253918();
            result = false;
            if (current == 0) result = func_002539e8(value, 0) == 0;
        }
    }
    return result;
}
