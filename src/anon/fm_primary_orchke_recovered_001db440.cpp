#include "../common/types.h"
extern "C" u8 D_003529d8[];
extern "C" u8 D_003529f0[];
extern "C" u8 D_00352a08[];
extern "C" u32 func_001050d8(u64);
extern "C" void func_001daef8(u32, u16*);

u32 func_001db440(u16* object) {
    switch (*object) {
    case 0: {
        u32 result = func_001050d8(0x70);
        func_001daef8(result, object);
        *(u8**)result = D_00352a08;
        return result;
    }
    case 1: {
        u32 result = func_001050d8(0x70);
        func_001daef8(result, object);
        *(u8**)result = D_003529f0;
        return result;
    }
    case 2: {
        u32 result = func_001050d8(0x70);
        func_001daef8(result, object);
        *(u8**)result = D_003529d8;
        return result;
    }
    }
    return 0;
}
