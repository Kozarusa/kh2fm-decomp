#include "../common/types.h"
// why: 16-byte alignment selects the 64-byte block-move loop of the original (v1 with 8-byte alignment copied 32 bytes per iteration)
struct __attribute__((aligned(16))) Block {
    u64 words[8696];
};
extern "C" Block D_0032bb30;
extern "C" Block D_01d499b0;
extern "C" u8 D_01d5a970[];
// why: void, as in the accepted definition fm_primary_fourwordfresh_recovered_00195558.cpp
extern "C" void func_00195558(void*);

void func_001cd2b8(void) {
    D_01d499b0 = D_0032bb30;
    u8* source = (u8*)&D_0032bb30;
    u8* record = D_01d5a970;
    // why: an unsigned 16-bit fill makes the constant li 0xffff (ori form) as in the original; a direct s16 store of 0xffff emits li -1
    u16 fill = 0xffff;
    u8 first = source[12];
    s16* halves = (s16*)(record + 4);
    record[1] = source[13];
    halves[0] = fill;
    halves[1] = fill;
    halves[2] = fill;
    record[0] = first;
    record[2] = source[14];
    func_00195558(record + 12);
    func_00195558(record + 2100);
}
