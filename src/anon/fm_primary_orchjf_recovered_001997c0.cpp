#include "../common/types.h"
extern "C" u8* func_0016e920(u32);

u32 func_001997c0(u32* object) {
    u8* data = func_0016e920(*object);
    switch (data[4]) {
    case 4:
    case 13:
    case 21:
    case 23:
        return 1;
    }
    return 0;
}
