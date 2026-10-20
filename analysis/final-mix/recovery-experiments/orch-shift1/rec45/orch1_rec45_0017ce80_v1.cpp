#include "../common/types.h"
extern "C" f32 func_0017ce10(f32);

f32 func_0017ce80(f32 start, f32 target, f32 step) {
    f32 delta = target - start;
    f32 result;
    if (func_0017ce10(delta) < -step) {
        result = start - step;
    } else if (step < func_0017ce10(delta)) {
        result = start + step;
    } else {
        result = start + func_0017ce10(delta);
    }
    return func_0017ce10(result);
}
