#include "../common/types.h"
struct Handler {
    void (**vtable)(Handler*);
};
extern "C" u8 D_0035f590;
extern "C" u8 D_0035f591;
extern "C" Handler* D_0035f58c;

void func_00295810() {
    D_0035f590 = 0;
    D_0035f591 = 0;
    if (D_0035f58c != 0) {
        D_0035f58c->vtable[1](D_0035f58c);
        D_0035f58c = 0;
    }
}
