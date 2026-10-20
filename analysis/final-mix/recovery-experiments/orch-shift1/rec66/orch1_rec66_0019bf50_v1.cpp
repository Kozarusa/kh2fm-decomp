#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Object {
    u8 pad0[0x540]; Quad src;
    Quad dst;
    Quad vec;
    u8 pad1[0x50]; u64 flags;
    u32 result;
};
extern "C" u32 func_00185118(...);
extern "C" u64 func_00143928(...);

s32 func_0019bf50(Object* object, Quad* other) {
    func_00185118();
    if (&object->dst != &object->src) {
        object->dst = object->src;
    }
    if (&object->vec != other) {
        object->vec = *other;
    }
    object->flags = object->flags & ~1ull;
    func_00143928();
    return (s32)object->result & 1;
}