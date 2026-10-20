#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" u32 func_002b7fbc(u32);
extern "C" u32 func_002b9b78(void);
extern "C" u32 func_002b9ed0(void);
extern "C" u32 func_002ba390(void);
extern "C" u32 func_002bce40(s32);
extern "C" u32 func_002bce50(void*);

u32 func_002b9e80() {
    func_002b7fbc(0);
    func_002bce40((s32)D_01e2a410);
    func_002bce50(D_01e2a410);
    func_002b9b78();
    func_002ba390();
    return func_002b9ed0();
}
