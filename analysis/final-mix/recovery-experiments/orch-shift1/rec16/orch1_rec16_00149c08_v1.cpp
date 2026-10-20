#include "../common/types.h"
extern "C" u8 D_00348d68[];
extern "C" u32 func_0013a4c8(void);
extern "C" u32 func_0013a600(void);
extern "C" u32 func_001493b8(u8*);
extern "C" u32 func_00149428(u8*);

u32 func_00149c08(void) {
    func_0013a600();
    func_0013a4c8();
    func_001493b8(D_00348d68);
    return func_00149428(D_00348d68);
}
