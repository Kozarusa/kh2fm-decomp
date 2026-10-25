#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* table;
};
extern "C" Object* D_0035f208;
extern "C" u32 D_0035f218;
// why: plain C names for C++ methods (Tz::Jiminy::JmCommonLeave, Tz::LightCur::Leave, Tz::JmStory::LeaveAll,
// Tz::JmTreasure::LeaveAll, Tz::JmBattle::LeaveAll): the probe linker script defines only the plain symbols
// (a mangled reference failed the isolated link in orch1_lg408_0026d8c0_v1)
extern "C" void func_00274ac8();
extern "C" s32 func_00139d78(u32);
// why: called with no argument register set; result unused
extern "C" void func_0028f878();
// why: LightCur::Leave member, this pointer D_0035f218 in a0
extern "C" void func_0028d620(u32);
extern "C" void func_00276e28();
extern "C" void func_002945a8();
extern "C" void func_00295868();
extern "C" void func_00297010();
// why: a0 = -1 before the call
extern "C" void func_00297e00(s32);
extern "C" void func_002995a8();
extern "C" u32 func_0029aac0(s32);
extern "C" void func_0029ee38();
// why: a0 = -1 before the call
extern "C" void func_002a07f0(s32);
extern "C" void func_002a2150();
extern "C" void func_002a4df8();
extern "C" void func_002a6a18();
extern "C" void func_002a7760();
extern "C" void func_002a8a88();
// why: a0 = 1 before the call
extern "C" void func_002aecf0(s32);
extern "C" void func_00275cb8();
// why: it either tail-calls func_0023d820 (declared void at accepted call sites, no result) or returns a test result; no value of record
extern "C" void func_002763c8();

void func_002749f0() {
    func_00274ac8();
    if (func_00139d78((u32)D_0035f208) != 0) {
        Object* object = D_0035f208;
        object->table[5](object);
    }
    func_0028f878();
    func_0028d620(D_0035f218);
    func_00276e28();
    func_002945a8();
    func_00295868();
    func_00297010();
    func_00297e00(-1);
    func_002995a8();
    func_0029aac0(-1);
    func_0029ee38();
    func_002a07f0(-1);
    func_002a2150();
    func_002a4df8();
    func_002a6a18();
    func_002a7760();
    func_002a8a88();
    func_002aecf0(1);
    func_00275cb8();
    func_002763c8();
}
