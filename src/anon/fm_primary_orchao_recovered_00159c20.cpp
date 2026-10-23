#include "../common/types.h"
extern "C" u8 D_0036b370[];
extern "C" void func_00159be0();
extern "C" void func_00102c18(u32, u32, void*);
extern "C" void func_00162058(f32);

void func_00159c20() {
    func_00102c18(1, 0x6586, (void*)func_00159be0);
    f32* pointer = (f32*)D_0036b370;
    asm("" : "+r"(pointer));  // why: keeps the address materialized before the load
    func_00162058(*pointer);
}
