#include "../common/types.h"
extern "C" f32 D_01c61968;
extern "C" u8* D_00352130;
extern "C" void func_00191c30(f32);

void func_00191bf0(f32 scalar)
{
 f32 saved=scalar;
 D_01c61968=scalar;
 func_00191c30(*(f32*)(D_00352130+80)*saved);
}
