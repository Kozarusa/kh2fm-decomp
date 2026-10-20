#include "../common/types.h"
extern "C" u64 func_001dba18(u64, u64, u64);
extern "C" u64 func_001050d8(u64);
extern "C" u64 func_001db950(u64, u64, u64, u64);

u64 func_001db9a8(u64 first, u64 second, u64 third) {
    u64 result = func_001dba18(first, second, third);
    if (result == 0) {
        result = func_001050d8(0xa00);
        func_001db950(result, first, second, third);
    }
    return result;
}