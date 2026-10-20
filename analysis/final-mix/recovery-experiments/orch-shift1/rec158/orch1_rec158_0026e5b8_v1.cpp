#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" u8 func_00287db0(void);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_0026e638(u64);
extern "C" u32 func_0026e8a0(void);
s32 func_0026e5b8(u64 value) {
    u32 mode = func_00287bc0();
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    switch (mode) {
    case 0: func_0026e638(value); break;
    case 1: func_0026e8a0(); break;
    }
    return 0;
}
