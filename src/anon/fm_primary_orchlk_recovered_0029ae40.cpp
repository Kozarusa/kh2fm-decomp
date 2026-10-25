#include "../common/types.h"
extern "C" u32 D_0035f200;
extern "C" u8 D_0035f5c4;
extern "C" u16 D_00374ad8[];
extern "C" const void* D_00374940[9];
// why: copied from the recovered call site fm_primary_orchis_recovered_00276438.cpp (same D_0035f200 argument)
extern "C" u32 func_00288e88(u32);
// why: copied from recovered call sites (fm_primary_dependencyfamily_recovered_00272a00.cpp)
extern "C" u32 func_00287bc0(void);
// why: types copied from the recovered definition fm_primary_orcheq_recovered_0028f4a0.cpp; extern "C" because
// the C++ form fails the isolated link (probe linker script defines only the plain symbol, see v1)
extern "C" void func_0028f4a0(u16* pointer);
// why: no recovered call site; the 16-byte original reads no argument, stores 1 to D_0035f5b4 and writes no v0
extern "C" void func_0029ae30(void);
// why: no recovered call site; the original stores a0 as a byte at offset 4 of D_0035f5ac and writes no v0
extern "C" void func_0029e950(u32 value);
// why: no recovered call site; the original stores a1 and a2 as halfwords in a table indexed by a0, writes no v0
extern "C" void func_002765e8(s32 index, s32 first, s32 second);
// why: no recovered call site; reads no argument and ends returning the u32 result of func_00287cc0
extern "C" u32 func_0029af20(void);
// why: no recovered call site; reads no argument and ends returning the u32 result of func_00287cc0
extern "C" u32 func_0029b698(void);
// why: no recovered call site; reads no argument and ends returning the u32 result of func_00287cc0
extern "C" u32 func_0029be08(void);

void func_0029ae40() {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_00374940
    static const void* targets[9] asm("fm_switch_table_0029ae40") = {
        &&menu, &&cursor, &&reset, &&done, &&cursor, &&reset, &&done, &&cursor, &&reset};
    func_00288e88(D_0035f200);
    u32 mode = func_00287bc0();
    func_0028f4a0(D_00374ad8);
    func_0029ae30();
    u32 index = mode - 14;
    if (index >= 9) goto done;
    goto *D_00374940[index];
menu:
    func_0029af20();
    return;
done:
    return;
cursor:
    if (mode == 18) {
        func_0029e950(17);
    } else if (mode == 21) {
        func_0029e950(18);
    }
    func_002765e8(15, 0, 0);
    func_0029b698();
    return;
reset:
    D_0035f5c4 = 0xff;
    func_0029be08();
}
