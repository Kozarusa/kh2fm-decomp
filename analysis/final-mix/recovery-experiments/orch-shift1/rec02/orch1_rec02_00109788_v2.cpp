#include "../common/types.h"
extern "C" u64 func_001094e0(...);
extern "C" u32 func_00133c60(...);

bool func_00109788(u64 first, u64 second) {
    u64 owner = first;
    u64 item = second;
    if (func_001094e0(item) == 0) {
        func_00133c60(owner, item, 0, 0, 0);
        return true;
    }
    return false;
}
