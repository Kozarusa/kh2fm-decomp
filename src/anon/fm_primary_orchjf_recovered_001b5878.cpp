#include "../common/types.h"
struct Gauge {
    u8 pad[12];
    u32 flags;
};
struct Limit {
    u8 pad[0xa8];
    Gauge gauge;
};
extern "C" u32 func_001d1d68(...);

// Preserve original registry aliases.
void func_001b5878(Limit* object) asm("_ZN2YS5LIMIT11close_gaugeEv");

void func_001b5878(Limit* object) {
    Gauge* gauge = &object->gauge;
    if (object->gauge.flags & 4) {
        func_001d1d68(gauge);
    }
}
