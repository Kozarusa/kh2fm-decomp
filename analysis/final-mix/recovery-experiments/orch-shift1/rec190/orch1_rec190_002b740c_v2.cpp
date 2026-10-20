#include "../common/types.h"

u64 func_002b740c(u32 first, u32 second, u32 third, u32 fourth)
{
    volatile u32* payload = (volatile u32*)__builtin_frame_address(0);
    payload[0] = first;
    payload[1] = second;
    payload[2] = third;
    payload[3] = fourth;
    return 0;
}
