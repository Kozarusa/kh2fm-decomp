#include "../common/types.h"

extern "C" u8 D_0034a800[];
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f98[];
extern "C" u8* D_00347f80;
extern "C" u64 func_002361d0(...);
extern "C" u64 func_00239870(...);

typedef u64 (*Callback)(u8*, u8*);
struct VTable {
    u32 padding;
    Callback callback;
};

u64 func_0031cf18(u8* object) {
    *(u32*)object = (u32)D_0034a800;
    func_002361d0(object + 416);
    *(u32*)object = (u32)D_00347e60;
    func_00239870(object + 24);
    register u32 globalBase asm("$14") = 0x00340000; // why: keeps D_00347f80 high half in t6
    *(u32*)object = (u32)D_00347f98;
    asm volatile("" ::: "memory"); // why: keeps store order
    u8* root = *(u8**)(globalBase + 32640);
    u8* receiver = *(u8**)(root + 20);
    VTable* table = *(VTable**)receiver;
    register Callback callback asm("$15") = table->callback; // why: keeps indirect callee in t7
    return callback(receiver, object);
}
