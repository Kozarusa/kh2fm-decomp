#include "../common/types.h"
extern "C" u8* D_01c61b08;
extern "C" void func_00196698(s32);
extern "C" s32 func_00196388(u8, u8);
extern "C" void func_001963f8(s32);

void func_00196710(s32 index) {
    func_00196698(index);
    u8* entry = (u8*)(index * 2 + (u32)D_01c61b08);
    s32 result = func_00196388(entry[2], entry[3]);
    if (result >= 0) {
        func_001963f8(result);
    }
}
