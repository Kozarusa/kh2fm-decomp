#include "../common/types.h"
struct Handler {
    void (**vtable)(Handler*);
};
extern "C" u8 D_0035f5a8;
extern "C" u8 D_0035f5a9;
extern "C" Handler* D_0035f5a4;

void func_00299550() {
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    if (D_0035f5a4 != 0) {
        D_0035f5a4->vtable[1](D_0035f5a4);
        D_0035f5a4 = 0;
    }
}
