#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" u32 func_002baa78(void);
extern "C" u32 func_002bcfe8(u8*);
extern "C" u32 func_002bd030(u8*);
extern "C" u32 func_002bd078(u8*);
extern "C" u32 func_002bd0b8(u8*);
extern "C" u32 func_002bd100(u8*);
extern "C" u32 func_002bd140(u8*);

u32 func_002b9ed0(void) {
    func_002baa78();
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    func_002bd078(D_01e2a410);
    func_002bd0b8(D_01e2a410);
    func_002bd100(D_01e2a410);
    return func_002bd140(D_01e2a410);
}
