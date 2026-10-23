#include "../common/types.h"
extern "C" u32 func_00105110(void*);
extern "C" u32 func_002cff98(void*);
extern "C" u32 func_002e7328(void*);
extern "C" char func_00362908;

u32 func_002db928(u32* object) {
    *object = (u32)(long)&func_00362908;
    func_002e7328((u8 *)object + 2976);
    func_002cff98(object);
    return func_00105110(object);
}
