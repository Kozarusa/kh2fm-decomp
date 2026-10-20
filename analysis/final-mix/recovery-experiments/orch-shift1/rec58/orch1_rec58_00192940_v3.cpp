#include "../common/types.h"
extern "C" u32 func_00192868(...);

struct Six {
    s32 word[6];
};

void func_00192940(u64 first, u64 second, Six* source) {
    Six copy = *source;
    func_00192868(first, second, &copy);
}