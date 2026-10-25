#include "../common/types.h"
extern "C" f32 func_001065a8(f32, f32);

f32 func_002deac0(f32* object, f32 first, f32 second) {
    if (first == second) {
        object[6] = first;
    } else {
        object[6] = func_001065a8(first, second);
    }
              object[6] = object[6] * 0.01f;
    return object[6];
}
