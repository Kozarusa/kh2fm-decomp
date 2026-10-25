#include "../common/types.h"
struct Object;
typedef void (*ObjectMethod)(Object*);
struct Object { ObjectMethod* methods; };
extern "C" s32 D_0035f2ec;
extern "C" s32 D_0035f318;
extern "C" s32 D_0035f2f0;
extern "C" s32 D_0035f2f4;
extern "C" Object* D_0035f31c;
extern "C" s32 D_0035f2e8;
// why: no argument registers are set before these calls and their v0 is not read here, so the return type does not affect this caller
extern "C" void func_0028c4f8(void);
extern "C" void func_0023ede8(void);
extern "C" void func_00288b78(void);
extern "C" void func_0023ed38(void);
extern "C" void func_00287c20(void);
extern "C" void func_00287f30();
extern "C" s32 func_001991a8(s32, s32);

void func_00287a28(void) {
    func_0028c4f8();
    func_0023ede8();
    func_00288b78();
    func_0023ed38();
    D_0035f2ec = -1;
    D_0035f318 = 0;
    D_0035f2f0 = 0;
    D_0035f2f4 = 0;
    func_00287c20();
    if (D_0035f31c != 0) {
        D_0035f31c->methods[4](D_0035f31c);
        D_0035f31c = 0;
    }
    func_00287f30();
    if (D_0035f2e8 != 0) {
        func_001991a8(D_0035f2e8, 0);
    }
    D_0035f2e8 = 0;
}
