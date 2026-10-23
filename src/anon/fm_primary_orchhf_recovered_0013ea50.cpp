#include "../common/types.h"
union Cell { s32 word; f32 value; s16 half; };
extern "C" f32 D_0036adb0;
extern "C" void func_002f3cd8(u8*, u8*, u8*);

void func_0013ea50(u8* object, u8* matrix, u8* vector, Cell* x, Cell* y) {
    func_002f3cd8(vector, matrix, vector);
    register f32* pointer asm("$15") = &D_0036adb0; // why: original builds the full address in t7
    asm("" : "+r"(pointer)); // why: original loads the scale through 0(t7)
    f32 scale = pointer[0];
    x->word = (s32)(((f32*)vector)[0] * scale);
    y->word = (s32)(((f32*)vector)[1] * scale);
    x->word = *(s16*)(object + 8) * 16 + x->word + 0x7000;
    y->word = *(s16*)(object + 10) * 16 + y->word + 0x7300;
}
