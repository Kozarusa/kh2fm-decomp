#include "../common/types.h"
struct Snapshot {
    u32 words[6];
};
extern "C" void func_00192800(u64, u64, Snapshot);

void func_00192818(u64 first, u64 second, Snapshot* source) {
    func_00192800(first, second, *source);
}
