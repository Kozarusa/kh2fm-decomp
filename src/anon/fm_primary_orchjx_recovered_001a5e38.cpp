#include "../common/types.h"
extern "C" u32* D_01c6cb20;
extern "C" u8 D_0035080c[];
extern "C" void func_001a5d48(u32*);
extern "C" void func_00105110(u32*);
extern "C" void func_001de450(void*);

void func_001a5e38() {
    u32* node = D_01c6cb20;
    while (node != 0) {
        u32* next = (u32*)node[3];
        // why: original re-tests node inside the loop (inlined null-checked delete)
        if (node != 0) {
            func_001a5d48(node);
            func_00105110(node);
        }
        node = next;
    }
    s32 entry = (s32)D_0035080c;
    s32 end = entry + 264;
    do {
        if (*(s32*)entry != 0) {
            func_001de450((void*)entry);
        }
        entry += 44;
    } while (entry < end);
}
