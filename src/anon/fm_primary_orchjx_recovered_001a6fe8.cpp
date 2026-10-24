#include "../common/types.h"
struct Window;
struct WindowVtable {
    u8 pad0[0x20];
    void (*update)(Window*);
};
struct Window {
    WindowVtable* vtable;
    u8 pad4[0x6c];
    s32 state;
};
struct Request {
    u16 kind;
    u16 pad2;
    s32 value;
};
struct Context {
    u8 pad0[0x10];
    s32 task;
};
extern "C" u32 func_001050d8(u64);
extern "C" void func_001ad228(u8* object, s32 value);
extern "C" u32 func_001ac7c8(void*,s32);
// why: no accepted source calls it; the definition is void(), but this caller passes a0 = 14 and tests v0
extern "C" s32 func_001a74f8(s32);
extern "C" u32 func_00102448(s32,u32);

s32 func_001a6fe8(Request* request, Context* context) {
    Window* window; // why: declared before the goto into the loop label
    s32 value; // why: declared before the goto into the loop label
    s32 task = context->task;
    if (request->kind == 1) {
        value = request->value;
        window = (Window*)func_001050d8(0xb6c);
        asm("" : "+r"(value)); // why: original moves a1 before a0 for this call
        func_001ad228((u8*)window, value);
        func_001ac7c8((void*)func_001050d8(0x1c), (s32)window);
    // why: goto loop keeps the single top test and places the yield block after the epilogue
    wait:
        if ((window->state ^ 3) != 0) { // why: original tests the state with xori + beqzl
            if (func_001a74f8(14)) {
                goto yield;
            }
        }
        window->vtable->update(window);
    }
    return 1;
yield:
    func_00102448(task, 0);
    goto wait;
}
