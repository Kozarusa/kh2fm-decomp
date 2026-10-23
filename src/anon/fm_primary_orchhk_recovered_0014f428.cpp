#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object { Method* table; };
extern "C" Object* D_0034a434;
extern "C" Object* D_0034a430;
extern "C" Object* D_0034a42c;
extern "C" Object* D_0034a428;

// Preserve original registry aliases.
void func_0014f428() asm("_Z13func_0014f428Pv");

void func_0014f428() {
    if (D_0034a434 != 0) {
        D_0034a434->table[4](D_0034a434);
        D_0034a434 = 0;
    }
    if (D_0034a430 != 0) {
        D_0034a430->table[4](D_0034a430);
        D_0034a430 = 0;
    }
    if (D_0034a42c != 0) {
        D_0034a42c->table[4](D_0034a42c);
        D_0034a42c = 0;
    }
    if (D_0034a428 != 0) {
        D_0034a428->table[4](D_0034a428);
        D_0034a428 = 0;
    }
}
