#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
// why: no recovered call site; tail-call targets declared void (ruling #36: the default exit is an own temporary)
extern "C" void func_002af0a0(void);
extern "C" void func_002af748(void);
extern "C" void func_002afe18(void);
extern "C" void func_002b05f8(void);
extern "C" void func_002b14f0(void);
extern "C" void func_002a2818(void);

void func_002af010(void) {
    switch (func_00287bc0()) {
    case 27:
        func_002af0a0();
        return;
    case 28:
        func_002af748();
        return;
    case 29:
        func_002afe18();
        return;
    case 30:
    case 31:
        func_002b05f8();
        return;
    case 32:
        func_002b14f0();
        return;
    case 33:
        func_002a2818();
        return;
    }
}
