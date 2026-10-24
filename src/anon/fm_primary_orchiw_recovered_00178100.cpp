#include "../common/types.h"
extern "C" s32 D_0034ece8;
extern "C" void func_00140d38(u8*, s32);
extern "C" void func_001586b8(void);
extern "C" void func_00159700(void);
extern "C" s32 func_00194898(void);

void func_00178100(u8* object) {
    switch (D_0034ece8) {
    case 0:
        func_00140d38(object, func_00194898() != 0);
        break;
    case 1:
        func_00140d38(object, 0);
        func_00159700();
        break;
    case 2:
        func_00140d38(object, 2);
        break;
    case 3:
        func_00140d38(object, 0);
        func_001586b8();
        break;
    }
}
