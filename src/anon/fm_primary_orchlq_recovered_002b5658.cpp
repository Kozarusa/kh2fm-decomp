#include "../common/types.h"
struct SelectObject;
// why: object at D_0035f658 dispatches through slot 20 (0x14) of its vtable with itself in a0
struct SelectVtable {
    u8 pad[20];
    void (*leave)(SelectObject*);
};
struct SelectObject {
    SelectVtable* vtable;
};
extern "C" SelectObject* D_0035f658;
extern "C" u32 D_0035f64c;
extern "C" u32 D_0035f678;
// why: original passes the object in a0 and tests v0; recovered call sites declare it u32
extern "C" u32 func_00139d78(SelectObject*);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
// why: a0 holds one word argument; recovered sites use (...) which does not change this call's codegen
extern "C" u32 func_0028be58(u32);
extern "C" u32 func_0028be18(u32);
// why: accepted definition Tz::CmSLBase::LeaveListItem (tozawa/cmenu_slbase.cpp) is void; plain symbol resolves via the build's func_ alias
extern "C" void func_002b5af0(void);

void func_002b5658(void) {
    if (D_0035f658 != 0 && func_00139d78(D_0035f658) != 0) {
        D_0035f658->vtable->leave(D_0035f658);
    }
    if (D_0035f64c != 0 && func_0028acc8(D_0035f64c) != 0) {
        func_0028abe0(D_0035f64c);
    }
    if (func_0028be58(D_0035f678) != 0) {
        func_0028be18(D_0035f678);
    }
    func_002b5af0();
}
