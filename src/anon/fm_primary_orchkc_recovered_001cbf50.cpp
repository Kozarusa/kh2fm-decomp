#include "../common/types.h"
extern "C" f32 D_0036e164;
extern "C" f32 D_0036e168;
extern "C" f32 D_0036e16c;

f32 func_001cbf50(f32 value) {
    if (0.0f < value) {
        f32* limit = &D_0036e164;
        asm("" : "+r"(limit)); // why: original forms the full address with addiu, then loads at offset 0
        f32 first = *limit;
        if (first < value) {
            f32 bound = first;
            asm("" : "+f"(bound)); // why: original keeps the loop bound in its own register, copied from the entry-test value
            do {
                f32* step = &D_0036e168;
                asm("" : "+r"(step)); // why: original forms the full address with addiu, then loads at offset 0
                value = value - *step;
            } while (bound < value);
        }
    } else {
        f32* limit = &D_0036e16c;
        asm("" : "+r"(limit)); // why: original forms the full address with addiu, then loads at offset 0
        register f32 bound asm("$f1") = *limit; // why: original keeps the lower bound in $f1 and the step in $f0
        while (value < bound) {
            f32* step = &D_0036e168;
            asm("" : "+r"(step)); // why: original forms the full address with addiu, then loads at offset 0
            register f32 delta asm("$f0") = *step; // why: original loads the step into $f0
            value = value + delta;
        }
    }
    return value;
}
