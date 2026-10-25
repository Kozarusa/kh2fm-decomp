#include "../common/types.h"
struct DisposableObject;
struct DisposableTable {
    void* first;
    void (*dispose)(DisposableObject*);
};
struct DisposableObject {
    DisposableTable* table;
};
extern "C" DisposableObject* D_0035f2b0;
extern "C" u32 D_0035f2b4;
extern "C" u8* D_0035f2b8;
extern "C" u8 D_00347e60[];
// why: copied from the accepted call site in fm_primary_orchac_recovered_00315678.cpp
extern "C" void func_00106420(u32);
// why: copied from the accepted call site in fm_primary_orchfv_recovered_0031b648.cpp
extern "C" void func_002361d0(u8*);
// why: copied from the accepted call site in fm_primary_orchfv_recovered_0031b648.cpp
extern "C" s32 func_00239870(u8*);
// why: copied from the accepted call site in fm_primary_orchgk_recovered_0031c928.cpp
extern "C" void func_0031a840(u32);
// why: no recovered call site; one pointer argument in a0, result unused here
extern "C" void func_0031abd8(u8*);
// why: return type from the accepted call site in fm_primary_oneword_recovered_00232510.cpp; one pointer argument in a0
extern "C" u32 func_0031acc0(u8*);

void func_002830b8(void) {
    if (D_0035f2b0 != 0) {
        D_0035f2b0->table->dispose(D_0035f2b0);
        D_0035f2b0 = 0;
    }
    if (D_0035f2b4 != 0) {
        func_00106420(D_0035f2b4);
        D_0035f2b4 = 0;
    }
    u8* object = D_0035f2b8;
    u8* view = object + 0x1a0;
    if (object != 0) {
        func_0031abd8(object + 0x6a0);
        func_0031abd8(object + 0x508);
        func_0031acc0(object + 0x354);
        *(u8**)(object + 0x1a0) = D_00347e60;
        func_00239870(object + 0x1b8);
        func_0031a840((u32)view);
        func_002361d0(object);
        func_00106420((u32)object);
        D_0035f2b8 = 0;
    }
}
