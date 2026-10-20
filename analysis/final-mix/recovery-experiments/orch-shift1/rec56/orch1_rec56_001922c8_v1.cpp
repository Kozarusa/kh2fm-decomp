#include "../common/types.h"
struct Entry { s32 pointer; s32 other; };
extern "C" Entry D_01c61970[];
extern "C" void func_00170950(s32);
extern "C" void func_00192028(s32);

void func_001922c8(s32 index) {
    s32 pointer = D_01c61970[index].pointer;
    if (pointer != 0) {
        func_00170950(pointer);
        func_00192028(index);
    }
}