#include "../common/types.h"

f32 func_002d48b8(f32 value) {
    if (0.0f < value) {
        while (3.1415927f < value) {
            value = value - 6.2831855f;
        }
    } else {
        while (value < -3.1415927f) {
            value = value + 6.2831855f;
        }
    }
    return value;
}
