#include "../common/types.h"
extern "C" u32 func_0027dc08(...);
extern "C" u32 func_00103550(...);
extern "C" u8 func_00103b38(...);
extern "C" u32 func_00253180(...);
u32 func_002534e0() {
    func_0027dc08();
    u32 type = func_00103550();
    u32 running = func_00103b38();
    if (running != 0 && type == 50) return running;
    return func_00253180(14, -1);
}
