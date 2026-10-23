#include "../common/types.h"

extern "C" void* D_00361f60;
extern "C" void* func_002d1878(void*);
extern "C" void func_002d2740(void*, void*, void*, f32, f32);

void* func_002d6d10(void* self, void* arg1, void* arg2) {
    void* obj = D_00361f60;
    void* r1 = func_002d1878(obj);
    void* r2 = func_002d1878(obj);
    func_002d2740(self, obj, arg2,
                  *(f32*)((u8*)r1 + 0xd0),
                  *(f32*)((u8*)r2 + 0xd4));
    return self;
}
