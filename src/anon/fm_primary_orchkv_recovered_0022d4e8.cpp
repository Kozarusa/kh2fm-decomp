#include "../common/types.h"
extern "C" u8* D_0035dcfc;
// why: the accepted definition in fm_resume_recovered_08.cpp takes three u64; that type emitted extra 64-bit argument conversions in probes v2/v3 that the original lacks, so 32-bit words are passed; extern "C" because the C++ declaration failed the isolated link in v1 (the probe linker script defines only the plain symbol)
extern "C" void func_0022f5a0(u32 entry, s32 key, s32 index);

void func_0022d4e8(u8* base) {
    if (D_0035dcfc != 0) {
        s32 unused = -1;
        s32 enabled = 1;
        s32 offset = 0;
        s32 count = 95;
        do {
            s32* object = (s32*)(offset + (u32)D_0035dcfc);
            offset += 40;
            if (object[0] != unused) {
                if (*(s8*)(base + object[1] + 6) != 0) {
                    if (*((u8*)object + 22) == enabled) {
                        func_0022f5a0((u32)((u8*)object + 23), object[0], object[1]);
                    }
                }
            }
            --count;
        } while (count >= 0);
    }
}
