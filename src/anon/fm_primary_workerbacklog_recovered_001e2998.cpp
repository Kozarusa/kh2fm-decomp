#include "../common/types.h"
extern "C" void func_001e2898(void*);
extern "C" void func_00105110(void*);
extern "C" void* D_00352bd0;

void func_001e2998(void)
{
    void* object = D_00352bd0;
    if (object != 0) {
        func_001e2898(object);
        func_00105110(object);
    }
    D_00352bd0 = 0;
}
