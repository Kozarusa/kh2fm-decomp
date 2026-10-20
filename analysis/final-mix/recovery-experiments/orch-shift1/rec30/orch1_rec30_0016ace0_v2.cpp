#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036c1b4;
extern "C" u32 func_001ba028(u8*);
extern "C" void func_00193608(u8*);

void func_0016ace0(u8* object, Quad* vector) {
    func_001ba028(object);
    Quad* position = (Quad*)(object + 1344);
    if (position != vector) {
        *position = *vector;
    }
    *(f32*)(object + 1356) = D_0036c1b4;
    func_00193608(object);
}