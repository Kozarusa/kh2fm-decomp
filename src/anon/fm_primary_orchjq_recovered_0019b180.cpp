#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef s32 (*Handler)(s32*, kn::FVector*);
extern "C" s32 func_00186078(s32);
extern "C" s32 func_0016c028(s32);
extern "C" u16 func_0016bff0(s32);
extern "C" s32 func_001991a8(s32, s32);

s32 func_0019b180(u8* owner) {
    s32 object = 0;
    while ((object = func_00186078(object)) != 0) {
        kn::FVector key;
        key = *(kn::FVector*)func_0016c028(object);
        s32* node = 0;
        for (;;) {
            s32* next;
            if (node == 0) {
                next = *(s32**)(owner + 12);
            } else {
                next = (s32*)node[24];
            }
            if (next == 0) {
                break;
            }
            node = next;
            if (((Handler)*(s32*)(*node + 8))(node, &key) != 0) {
                u8* info = *(u8**)(owner + 8);
                if ((*(u32*)(object + 0xaa8) & 0xfffeffff) != *(u16*)(info + 2)) {
                    func_001991a8(*(s32*)(*(u8**)(owner + 8) + 0x1c), func_0016bff0(object));
                }
                *(u32*)(object + 0xaa8) = *(u16*)(*(u8**)(owner + 8) + 2);
                break;
            }
        }
    }
    return object;
}
