#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);
// why: form of accepted caller fm_primary_orchdm_recovered_001d4f40.cpp; the u64 form of the other accepted callers is not exact here (probe orch1_rcfix27_001d89e8_v2)
extern "C" u32 func_001d1b60(u8*, s32);

// why: word read masked to bit 0, then tested as a byte (lw, andi 1, andi 0xff), as in accepted sibling func_001d8618
union FlagWord {
    u32 word;
    u8 byte;
};

void func_001d89e8(s32 digit, s32 value, s32 index) {
    if (!func_001bb4a0()) {
        return;
    }
    // why: separate temporary for the first record address keeps the original addu operand order
    u32 record = func_001bbcb0() + index * 56;
    FlagWord flag;
    flag.word = *(u32*)(record + 244);
    flag.word = flag.word & 1u;
    if (flag.byte == 0) {
        return;
    }
    u8* entry = (u8*)(func_001bbcb0() + index * 56) + 232;
    s32 current = *(s32*)(entry + 44);
    s32 scale = 1;
    if (digit > 0) {
        s32 count = digit;
        do {
            count--;
            scale *= 10;
        } while (count != 0);
    }
    // why: void under ruling #36: exit A direct (IsExec), exit B own (record temporary), this tail exit direct by chain (1d1b60 -> 1d17b0); an own exit is present, so the chain result is not returned
    func_001d1b60(entry, current + (value - (current / scale) % 10) * scale);
}
