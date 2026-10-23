#include "../common/types.h"
typedef s32 (*Method)(u8*);
extern "C" u32 func_00139510(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0031a260(...);

s32 func_00151c70(u8* object) {
    u8* current;
    u8* entry;
    s32 index;
    s32 result;
    if (func_00139d78(object) != 0) {
        register Method method asm("$15") = (*(Method**)object)[5]; // why: original calls through t7
        method(object);
    }
    if (func_00139d78(object + 48) != 0) {
        func_00139510(object + 48);
    }
    current = object;
    entry = object + 840;
    for (index = 0; index < 5; index++) {
        result = func_00139d78(entry);
        if (result != 0) {
            *(s32*)(current + 1236) = 0;
            func_001396b0(entry);
            if (*(s32*)(current + 1236) != 0) {
                *(s32*)(current + 1240) = 0;
                func_001396b0(entry);
                if (*(s32*)(current + 1240) != 0) {
                    func_0031a260(entry, 0);
                }
            }
            register Method method asm("$15") = (*(Method**)(current + 840))[5]; // why: original calls through t7
            result = method(entry);
        }
        current += 408;
        entry += 408;
    }
    return result;
}
