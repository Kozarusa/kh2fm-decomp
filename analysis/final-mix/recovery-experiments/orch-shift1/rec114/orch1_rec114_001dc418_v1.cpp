#include "../common/types.h"
struct Object {
    void* table;
    u8 pad[24];
    s32 child;
};
extern "C" u8 D_00352b48[];
extern "C" u8 D_00352ae0[];
extern "C" s32 D_00352ae8;
extern "C" u32 func_001e2c00(s64);
extern "C" u32 func_001e6c00(u64);
extern "C" void func_00321c50(void*, void*);
extern "C" void func_001dc4b8(Object*);

void func_001dc418(Object* object) {
    object->table = D_00352b48;
    s32 child = object->child;
    if (child != 0) {
        func_001e2c00(child);
        func_001e6c00(object->child);
    }
    func_00321c50(D_00352ae0, object);
    D_00352ae8 = D_00352ae8 - 1;
    func_001dc4b8(object);
}