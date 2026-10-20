#include "../common/types.h"
struct Inner { u8 pad[0x22]; u8 limit; };
struct Object { u8 pad0[8]; Inner* inner; u8 pad1[0x14]; u8 index; };
extern "C" s32 func_0019ad58(...);
extern "C" u32 func_0019ad00(s32,u64);
extern "C" u32 func_0019ae60(s32);

s32 func_0019ac80(Object* object) {
    // why: original keeps the result in t5 ($13)
    register s32 result asm("$13") = 0;
    if (object->index < 200) {
        if (func_0019ad58(object) <= object->inner->limit) {
            do {
                func_0019ae60((s32)object);
                if (func_0019ad00((s32)object, object->index) != 0) {
                    return 1;
                }
            } while (object->index < 200);
        }
    }
    return result;
}