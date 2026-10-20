#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union Packet {
    Quad quad;
    u64 dword[4];
};
extern "C" u64 D_0036a288;
extern "C" Packet* func_00133ba0(u64, s32, s32);

void func_00109708(u64 context) {
    volatile Packet* packet = func_00133ba0(context, 2, 0x13000000);
    packet->quad = 0;
    packet->dword[1] = (packet->dword[1] & ~0xfULL) | 0xe;
    packet->dword[0] = (((packet->dword[0] & ~0x7fffULL) | 0x8001) & 0x0fffffffffffffffULL) | (1ULL << 60);
    packet->dword[2] = D_0036a288;
    packet->dword[3] = 0x16;
}
