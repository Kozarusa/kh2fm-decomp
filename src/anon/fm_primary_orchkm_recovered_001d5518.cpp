#include "../common/types.h"
extern "C" u32 D_00350438;
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_00196ca8(...);
extern "C" u32 func_00196f00(...);
extern "C" s32 func_0016b740(...);
// why: types of the accepted definition fm_primary_orchbg_recovered_00185de0.cpp; extern "C" because asm-alias declarations fail the isolated probe link (seen in lg340 001d0980 v1)
extern "C" u32 func_00185de0(void);
// why: types of the accepted definition fm_primary_orchje_recovered_00196e98.cpp, with C linkage for the probe link
extern "C" void func_00196e98(u8*, u32);
extern "C" u32 func_001d30f8(void*, u32, u32);

void func_001d5518(u32* source, u32 value, u8 flag) {
    if (source[1] == 0) {
        return;
    }
    u8* entry = (u8*)func_001050d8(0xb0);
    func_00196ca8(entry, source[0], source[1]);
    *(u32*)(entry + 8) = value;
    if (flag != 0) {
        *(u32*)entry |= 8;
    }
    *(u32*)(entry + 0x94) = source[3];
    *(u32*)(entry + 0x98) = source[4];
    if (source[6] != 0) {
        *(u32*)(entry + 0x9c) = 2;
        *(u32*)(entry + 0xa0) = source[6];
    } else if (source[5] != 0) {
        *(u32*)(entry + 0x9c) = source[5];
    }
    switch (source[2]) {
    case 0:
        break;
    case 902:
        func_00196e98(entry, func_00185de0());
        break;
    case 1679:
        func_001d30f8(entry + 0x40, 4, 0);
        break;
    case 1726:
        func_00196e98(entry, D_00350438);
        break;
    default:
        func_00196e98(entry, func_0016b740(source[2]));
        break;
    }
    func_00196f00(entry);
}
