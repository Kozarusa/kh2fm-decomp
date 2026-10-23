#include "../common/types.h"
typedef void* (*AllocFunc)(void*, s32, void*);
struct Allocator {
    AllocFunc* table;
};
extern "C" void func_001022c0(void*, Allocator*, s32, s32, s32);
extern "C" void func_00102528(Allocator*, void*);

// Preserve original registry aliases.
void* func_00102788(Allocator* object, s32 first, s32 second, s32 third) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");

void* func_00102788(Allocator* object, s32 first, s32 second, s32 third) {
    void* result = object->table[0](object, 72, __builtin_return_address(0));
    func_001022c0(result, object, first, second, third);
    func_00102528(object, result);
    return result;
}
