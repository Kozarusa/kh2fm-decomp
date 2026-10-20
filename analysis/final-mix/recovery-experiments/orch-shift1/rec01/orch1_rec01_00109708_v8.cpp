#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union Packet {
    Quad quad;
    u64 dword[4];
};
extern "C" u64 D_0036a288;
extern "C" Packet* func_00133ba0(u64, s32, s32);

void func_00109708(u64 context) {
    Packet* packet = func_00133ba0(context, 2, 0x13000000);
    packet->quad = 0;
    u64 mask = 0x0fffffffffffffffULL;
    u64 low = packet->dword[0];
    u64 high = packet->dword[1];
    high = (high & ~0xfULL) | 0xe;
    low = (low & ~0x7fffULL) | 0x8001;
    low = low & mask;
    low = low | (1ULL << 60);
    ((volatile Packet*)packet)->dword[1] = high;
    ((volatile Packet*)packet)->dword[0] = low;
    ((volatile Packet*)packet)->dword[2] = D_0036a288;
    ((volatile Packet*)packet)->dword[3] = 0x16;
}


