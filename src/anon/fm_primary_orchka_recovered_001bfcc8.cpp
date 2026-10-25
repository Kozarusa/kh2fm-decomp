#include "../common/types.h"

struct Object {
    u8 pad0[1416];
    u32 flags;
    u8 pad1[2764 - 1420];
    s32 count;
};

extern "C" u64 func_0016bda8(...);
// why: accepted fm_scalar_extra_recovered_12.cpp declares (...), which promotes the float to a double in a2 (orch1_lg273_001bfcc8_v1/v2 probes); return type kept, parameters from a0, a1, $f12
extern "C" u64 func_0016f000(s32, u8*, f32);
extern "C" s32 func_001991a8(s32, s32);

void func_001bfcc8(Object* object, s32 amount) {
    if (amount == 0) {
        return;
    }
    asm("" : "+r"(object)); // why: the original passes the saved s2 copy of object, not a0
    u8 buffer[16];
    func_0016bda8(buffer, object);
    s32 count = object->count;
    if (count < amount) {
        amount = count;
    }
    if (amount > 0) {
        s32 index = amount;
        do {
            index--;
            func_0016f000(2179, buffer, 0.0f);
        } while (index != 0);
    }
    object->count -= amount;
    if (object->flags & 0x80) {
        func_001991a8(80, amount);
    }
}
