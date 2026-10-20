#include "../common/types.h"
extern "C" u8 D_0034e888[];
extern "C" u32 *func_001050d8(u64);
extern "C" void func_002ee220(u32 *);
extern "C" void func_002ee5d8(u32 *, u32);
extern "C" void func_002edfa8(u32 *, u32 *);

void func_00175370(u32 *source) {
    u32 *object = func_001050d8(0x1280);
    u32 payload = *source;
    u32 *widget = object + 9;
    func_002ee220(object);
    object[0] = (u32)D_0034e888;
    func_002ee5d8(widget, payload);
    func_002edfa8(object, widget);
}