#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union Block {
    Quad quad;
    u64 dword[4];
};
extern "C" u32 func_00133ba0(...);

void func_00109690(u64 value) {
    Block* object = (Block*)func_00133ba0(value, 2, 0x13000000);
    object->dword[2] = 0;
    object->quad = 0;
    object->dword[1] = (object->dword[1] & ~0xfULL) | 0xe;
    object->dword[0] = (((object->dword[0] & ~0x7fffULL) | 0x8001ULL) & 0x0fffffffffffffffULL) | 0x1000000000000000ULL;
    object->dword[3] = 0x3f;
}
