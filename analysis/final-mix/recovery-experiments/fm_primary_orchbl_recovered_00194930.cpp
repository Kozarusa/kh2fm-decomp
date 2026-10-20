#include "../common/types.h"
extern "C" u8 D_0032bae0[];
extern "C" u8 D_0032bb30[];
extern "C" u32* func_001947c0(u64, u64);
extern "C" void func_001a9110(void*);

void func_00194930() {
    u32* record = func_001947c0(D_0032bae0[1], D_0032bae0[0]);
    func_001a9110(record + D_0032bb30[D_0032bae0[0] + 9196] + 4);
}
