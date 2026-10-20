#include "../common/types.h"
extern "C" u32 func_001a1db8(...);

void func_001a1d50(f32 delta, u8* object) {
    f32 limit = *(f32*)(object + 448);
    if (0.0f < limit) {
        f32 result = 0.0f;
        f32 sum = *(f32*)(object + 444) + delta;
        if (!(sum < 0.0f)) {
            result = limit;
            if (!(limit < sum)) {
                result = sum;
            }
        }
        *(f32*)(object + 444) = result;
        if (result == 0.0f) {
            func_001a1db8();
            return;
        }
    }
}
