#include "../common/types.h"

// Two independent FM functions previously merged into one 152-byte fallback
// range. Four-byte alignment padding separates the 100-byte caller from helper.
struct FmNodeList { u32 first, last; };
extern FmNodeList D_01e2bf00;
extern "C" f32 func_001065a8(f32, f32);
void func_002e73a8(u32* object);

void func_002e7340(u32* object, u32 word, s32 count, u8* stream, f32 first, f32 second) {
    object[1] = word;
    object[3] = (u32)(stream + 1);
    object[2] = count - 1;
    *(f32*)(object + 4) = first;
    *(f32*)(object + 5) = second;
    object[6] = *stream;
    if (D_01e2bf00.last == 0) {
        D_01e2bf00.last = (u32)object;
        D_01e2bf00.first = (u32)object;
        object[0] = 0;
    } else {
        *(u32*)D_01e2bf00.last = (u32)object;
        object[0] = 0;
        D_01e2bf00.last = (u32)object;
    }
    func_002e73a8(object);
}
void func_002e73a8(u32* object) {
    *(f32*)(object + 7) = func_001065a8(*(f32*)(object + 4), *(f32*)(object + 5));
}
