#include "../common/types.h"
typedef void (*Callback)(u8*);
extern "C" u8 D_00361980[];
extern "C" u8 D_003637e0[];
extern "C" u32 func_00105110(u64);

u32 func_002beea8(u8* object) {
    *(u8**)object = D_00361980;
    u8* pointer = *(u8**)(object + 36);
    Callback callback = *(Callback*)(*(u8**)pointer + 12);
    callback(pointer);
    *(u8**)object = D_003637e0;
    return func_00105110((u64)object);
}
