#include "../common/types.h"
extern "C" u64 func_002bc0f0(void);

u64 func_002bc158(s64 value) {
    if (value != 0) {
        if (value >= 0) {
            return func_002bc0f0();
        }
    }
    return 0;
}
