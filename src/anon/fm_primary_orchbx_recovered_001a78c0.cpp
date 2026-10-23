#include "../common/types.h"
extern "C" void func_001a7a48(void*);
extern "C" u64 func_001a7da8(f32, f32, u64, void*);

u64 func_001a78c0(u64 object, f32 unused0, f32 unused1, f32 x, f32 y) {
    u8 buffer[48];
    func_001a7a48(buffer);
    func_001a7da8(x, y, object, buffer);
    return object;
}
