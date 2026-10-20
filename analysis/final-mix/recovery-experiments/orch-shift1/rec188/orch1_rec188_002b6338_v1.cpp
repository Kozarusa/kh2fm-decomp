#include "../common/types.h"
extern "C" u32 func_00192048(...);
extern "C" u64 func_00192e50(...);

u64 func_002b6338(u32 first, u32 second, u32 third, u32 flag) {
    u32 selector = flag != 0 ? 0xb7d5 : 0xb7d4;
    u32 first_result = func_00192048(third);
    u32 second_result = func_00192048(selector);
    return func_00192e50(first_result, first, second, second_result);
}
