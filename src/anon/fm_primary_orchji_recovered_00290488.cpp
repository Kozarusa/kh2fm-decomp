#include "../common/types.h"
struct Node {
    void (**vtable)(Node*);
};
extern "C" u32 func_00139d78(...);

void func_00290488(Node** object) {
    if (object[0] != 0) {
        if (func_00139d78(object[0]) != 0) {
            object[0]->vtable[5](object[0]);
        }
    }
    if (object[1] != 0) {
        if (func_00139d78(object[1]) != 0) {
            object[1]->vtable[5](object[1]);
        }
    }
}
