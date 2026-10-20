#include "../common/types.h"

extern "C" s8 D_00457458;
extern "C" u8 D_00457460[];
extern "C" u8 D_00142c88[];
extern "C" void func_002fd188(u8*);
extern "C" void func_00141988(u8*, u8*, u8*);

u8* func_00142208(u8* object, u16 index) {
    if (D_00457458 == 0) {
        D_00457458 = 1;
        func_002fd188(D_00142c88);
    }
    func_00141988(object, *(u8**)(object + 12) + (index << 4), D_00457460);
    return D_00457460;
}
