#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);

// Preserve original registry aliases.
u64 func_002b89e4(u32 input0, u32 input1, u32 input2) asm("_Z16wtarget_002b89e4jjjj");

u64 func_002b89e4(u32 input0, u32 input1, u32 input2)
{
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea)); // why: original keeps a 32-byte frame for the argument area
    // why: original transports arguments through the explicit frame pointer
    register void* frame asm("$30");
    // why: original establishes the frame pointer after saving it
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = input0;
    payload[1] = input1;
    payload[2] = input2;
    asm volatile("" ::: "memory"); // why: keeps the first field store after the argument stores
    u32 high = 0x48000;
    asm("" : "+r"(high)); // why: original rematerializes the offset for each store
    u32 first = payload[0] + high;
    asm volatile("" : "+r"(first)); // why: original forms the field address before loading the stored value
    *(volatile u32*)(first + 36) = payload[1];
    asm volatile("" ::: "memory"); // why: keeps store order
    u32 again = 0x48000;
    asm("" : "+r"(again)); // why: original rematerializes the offset for each store
    u32 second = payload[0] + again;
    asm volatile("" : "+r"(second)); // why: original forms the field address before loading the stored value
    *(volatile u32*)(second + 40) = payload[2];
    asm volatile("" ::: "memory"); // why: keeps the call setup after the field stores
    // why: original loads the base into t6
    register u32 base asm("$14") = payload[0];
    // why: original materializes the area offset in t7
    register u32 offset asm("$15") = 0x8000;
    asm("" : "+r"(offset)); // why: keeps the offset in its own register before the add
    // why: original forms the area address in t7 and then moves it to a2
    register u32 area asm("$15") = base + offset;
    asm volatile("" : "+r"(area)); // why: keeps the area address in t7 before the argument setup
    // why: original sets the first argument right after forming the area address
    register s32 count asm("$4") = 4;
    // why: original sets the second argument right after the first
    register s32 operation asm("$5") = 28;
    asm volatile("" : "+r"(count), "+r"(operation) : "r"(area)); // why: keeps both constants before the area move
    // why: original moves the area address into a2 before loading the fourth argument
    register u32 areaArgument asm("$6") = area;
    asm volatile("" : "+r"(areaArgument)); // why: keeps the area move before the a3 load
    // why: original keeps the callee result in t7 before moving it to v0
    register u64 result asm("$15") = func_002b6708(count, operation, areaArgument, payload[1], payload[2]);
    asm("" : "+r"(result)); // why: keeps the separate move from v0 to t7
    // why: original returns the t7 value through v0
    register u64 returned asm("$2") = result;
    asm("" : "+r"(returned)); // why: keeps the separate move from t7 to v0
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
