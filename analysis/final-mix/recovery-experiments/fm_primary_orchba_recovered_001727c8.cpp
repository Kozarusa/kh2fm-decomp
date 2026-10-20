#include "../common/types.h"
struct Holder {
    u32* first;
    u32* second;
    f32 scale;
};
extern "C" void func_001b0798(u32 first, u32 second, u32 flag, f32 scale);

void func_001727c8(Holder* holder) {
    func_001b0798(holder->first[1] + 0x4a0, holder->second[1], 1, holder->scale);
}
