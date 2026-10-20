#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Block64 {
    Quad q[4];
};
extern "C" u32 func_00142940(u32 target, Block64 block);

u32 func_00165830(u8* object, Block64 block) {
    return func_00142940(*(u32*)(object + 4), block);
}
