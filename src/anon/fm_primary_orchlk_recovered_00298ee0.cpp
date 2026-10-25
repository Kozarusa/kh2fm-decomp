#include "../common/types.h"
extern "C" u32 D_0035f59c;
extern "C" s8 D_0035f5a1;
extern "C" u8* D_0035f598;
extern "C" u8 D_0035f5a2;
extern "C" u32 func_0023f900(u32);
extern "C" s64 func_00292630();
extern "C" u8* func_002983d8(s32);
extern "C" u32 func_00293de8(s32);
extern "C" u32 func_002ff2e8(u8*, u32);
extern "C" void func_002feee8(u8*, u8*);
extern "C" u64 func_00293db8(s32,const char*);
// why: declaration copied from the accepted sibling 002b27c8, which has the same flushing/return shape
extern "C" u64 func_0023fa08(...);

s64 func_00298ee0() {
    u8 buffer[32];
    func_0023f900(D_0035f59c);
    s64 result = func_00292630();
    if (result != 0) return result;
    u8* album = func_002983d8(*(s16*)(D_0035f598 + D_0035f5a1 * 2 + 4));
    func_002ff2e8(buffer, func_00293de8(*(s8*)album));
    func_002feee8(buffer, album + 1);
    u64 data = func_00293db8(3, (const char*)buffer);
    result = func_0023fa08(D_0035f59c, data);
    D_0035f5a2 = 1;
    return result;
}
