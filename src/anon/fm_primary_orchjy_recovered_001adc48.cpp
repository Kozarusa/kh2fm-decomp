#include "../common/types.h"
typedef void (*LoadCallback)(u32, u32, s32);
struct Loader {
    u32 callback; // why: stored as a word so its clear may alias the u32 size reload (keeps the original store order)
    u8* target;
    u32 buffer;
    u32 size;
    s32 status;
};
extern "C" Loader D_00350cb0;
extern "C" u32 func_002f7dc8(...);
extern "C" void func_003058a0(u32);

void func_001adc48(s32 mode) {
    if (mode == 1 && D_00350cb0.callback != 0) {
        Loader* loader = &D_00350cb0;
        func_003058a0(0);
        if (func_002f7dc8() != 0) {
            loader->status = -1;
            ((LoadCallback)D_00350cb0.callback)(loader->buffer, loader->size, -1);
            D_00350cb0.callback = 0;
        } else {
            loader->status = 0;
            ((LoadCallback)D_00350cb0.callback)(loader->buffer, loader->size, 0);
            D_00350cb0.callback = 0;
            *(u32*)(loader->target + 8) += (loader->size + 2047) >> 11;
        }
    }
}
