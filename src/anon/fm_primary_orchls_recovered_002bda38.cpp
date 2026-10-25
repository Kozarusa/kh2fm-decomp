#include "../common/types.h"

// why: objects of the owned list are destroyed through vtable slot 1 (offset 4),
// the deleting destructor of a class with a virtual destructor; the list link is at 0x20
class ListedObject {
public:
    virtual ~ListedObject();
    u8 body[28];
    ListedObject* next;   // 0x20
};

struct Libretto {
    u8 header[4];
    s32 handle;            // 0x04
    u32 table;             // 0x08: reset to the base table on teardown
    u8 reserved0[4];
    ListedObject* objects; // 0x10
    u8 reserved1[84];
    s32 buffer;            // 0x68
};

// why: base table address stored as a word at 0x08, as the accepted 002eec58 stores it
extern "C" u32 D_003637e0[];
extern "C" s32 D_003617fc;
// why: worldmap::Libretto::leaveAllObj(); the object pointer (a0) is passed on unchanged
extern "C" void func_002be148(Libretto* libretto);
// why: declaration copied from the accepted caller 001922c8 (YS::CACHE_BUFF::Free)
extern "C" void func_00170950(s32);
// why: no accepted using site; a single word argument (a0) and no result used
extern "C" void func_001b86e0(s32 handle);
// why: the accepted definition 00170320 (YS::CACHE_BUFF::Clear) is void(s32)
extern "C" void func_00170320(s32 value);

void func_002bda38(Libretto* libretto)
{
    func_002be148(libretto);
    ListedObject* object = libretto->objects;
    while (object != 0) {
        ListedObject* next = object->next;
        delete object;
        object = next;
    }
    if (libretto->buffer != 0) {
        func_00170950(libretto->buffer);
    }
    func_001b86e0(libretto->handle);
    func_00170320(-200);
    D_003617fc = 0;
    libretto->table = (u32)D_003637e0;
}
