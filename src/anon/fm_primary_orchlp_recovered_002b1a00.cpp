#include "../common/types.h"
extern "C" u16 D_00374c68[];
extern "C" u32 func_00287bc0(void);
// why: single argument register a0 = -1 at the only site; same use as recovered 002b1aa0 (pointer to flags word)
extern "C" u32 func_002b23e0(s32 index);
// why: accepted definition in fm_scalar_recovered_07.cpp is void (s64, u8); extern "C" because the probe linker script defines only the plain symbol
extern "C" void func_00276c50(s64 message, u8 flag);

void func_002b1a00(void) {
    s32 message = -1;
    u32 mode = func_00287bc0();
    s32 index = 0;
    if (D_00374c68[0] != 0) {
        do {
            u16* entry = &D_00374c68[index * 2];
            if (mode == (s16)entry[1]) {
                message = entry[0];
                break;
            }
            index++;
        } while (D_00374c68[index * 2] != 0);
    }
    if (message == 20297) {
        u32* flags = (u32*)func_002b23e0(-1);
        if (*flags & 0x04000000) {
            message = 20696;
        }
    }
    func_00276c50(message, 0);
}
