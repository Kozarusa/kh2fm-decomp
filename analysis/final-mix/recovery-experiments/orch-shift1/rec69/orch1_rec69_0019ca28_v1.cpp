#include "../common/types.h"
struct Out {
    s32 a;
    s32 b;
    s32 c;
    u8* pointer;
};
extern "C" void func_001902a8(s32*, Out*);

void func_0019ca28(s32* object, s32* source) {
    Out out;
    out.pointer = 0;
    object[1] = source[0];
    object[2] = source[1];
    object[3] = source[2];
    object[4] = source[3];
    object[5] = source[4];
    func_001902a8(object + 1, &out);
    object[9] = out.pointer[1];
}