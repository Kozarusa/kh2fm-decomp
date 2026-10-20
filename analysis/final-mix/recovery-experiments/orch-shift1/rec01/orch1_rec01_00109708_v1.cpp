#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u64 D_0036a288;
extern "C" u64* func_00133ba0(u64, s32, s32);

void func_00109708(u64 context) {
    u64* packet = func_00133ba0(context, 2, 0x13000000);
    *(Quad*)packet = 0;
    u64 low = packet[0];
    u64 high = packet[1];
    high = (high & ~0xfULL) | 0xe;
    low = (low & ~0x7fffULL) | 0x8001;
    low = low & 0x0fffffffffffffffULL;
    low = low | (1ULL << 60);
    packet[1] = high;
    packet[0] = low;
    packet[2] = D_0036a288;
    packet[3] = 0x16;
}
