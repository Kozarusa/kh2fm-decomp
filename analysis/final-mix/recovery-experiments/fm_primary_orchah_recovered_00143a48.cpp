#include "../common/types.h"

extern "C" u32 D_00348804;
extern "C" u32 func_00141c18(...);
extern "C" u32 func_00141ff0(...);

void func_00143a48(u32 first, u32 second, u32 third) {
    u8 buffer[16];
    func_00141c18(D_00348804, 15, 4, 1, 1);
    func_00141ff0(D_00348804, first, second, buffer, third);
}
