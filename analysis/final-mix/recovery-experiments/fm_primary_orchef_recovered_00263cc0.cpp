#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00263d28();
extern "C" u32 D_0035f0dc;
extern "C" u32 D_0035f0c0;

u32 func_00263cc0() {
    u32 result = 0; if (D_0035f0dc != 0) {
    if (func_00139d78(D_0035f0c0) == 0) {
        if (func_00139d78(D_0035f0dc) != 0) func_00263d28();
    }
    result = func_00139d78(D_0035f0dc); } return result;
}
