#include "../common/types.h"
struct Object {u8 reserved[28];u32 value;};
extern "C" u32 func_001dc9e0(Object*);
extern "C" u32 func_001e6cd0(u32);

// Preserve original registry aliases.
u32 func_001dc5f8(Object* p) asm("_ZN3ryj6EFFECT3posEv");

u32 func_001dc5f8(Object* p) { func_001dc9e0(p);return func_001e6cd0(p->value); }
