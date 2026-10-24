#include "../common/types.h"
struct Handler {
    void (**vtable)(Handler*);
};
extern "C" u8 D_0035f580;
extern "C" u8 D_0035f581;
extern "C" Handler* D_0035f57c;

void func_00294550() {
    D_0035f580 = 0;
    D_0035f581 = 0;
    if (D_0035f57c != 0) {
        D_0035f57c->vtable[1](D_0035f57c);
        D_0035f57c = 0;
    }
}
