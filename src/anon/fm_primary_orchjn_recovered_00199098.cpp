#include "../common/types.h"
struct Block {
    u32 words[9];
};
extern "C" u32 func_00198bd0(s32,s32);
extern "C" u32 func_00198ee8(void*);

Block func_00199098(s32 index) {
    u8* object = (u8*)func_00198bd0(index, -1);
    func_00198ee8(object);
    return *(Block*)(object + 0x34);
}
