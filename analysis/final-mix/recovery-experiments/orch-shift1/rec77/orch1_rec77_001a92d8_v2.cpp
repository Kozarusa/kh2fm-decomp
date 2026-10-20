#include "../common/types.h"

extern "C" u32 func_0016e920(u32);
extern "C" u32 func_00170e58(void);
extern "C" u32 func_001a9218(void*);
extern "C" u32 func_001a9350(...);
extern "C" bool func_001a9758(...);

void func_001a92d8(u32* object, u32 id, u32 data) {
    u32* target = object;
    u32 size = data;
    func_001a9350();
    if (size == 0) {
        size = func_0016e920(id);
    }
    if (!func_001a9758(id, size)) {
        func_00170e58();
        target[1] = id;
    } else {
        target[1] = id;
    }
    target[2] = size;
    func_001a9218(target);
}
