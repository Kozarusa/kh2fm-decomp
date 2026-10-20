#include "../common/types.h"
extern "C" u32 func_00181500(u32);
extern "C" u32 func_001a6d08(u32);
extern "C" u32 func_001b8958(u32);

u32 func_001d5868(u16* entry) {
    switch (entry[0]) {
    case 1:
        return func_00181500(entry[1]);
    case 2:
        return func_001b8958(entry[1]);
    case 3:
        return func_001a6d08(entry[1]);
    }
    return 0;
}
