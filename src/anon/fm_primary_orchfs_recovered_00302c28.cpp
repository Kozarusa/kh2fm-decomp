#include "../common/types.h"
extern "C" void func_00304de8();
extern "C" void D_00304e48();
extern "C" void func_00304ec8();
extern "C" void D_00304f30();

struct Stream {
    void* field0;
    void* field4;
    void* field8;
    s16 mode;
    s16 descriptor;
    void* field10;
    void* field14;
    void* field18;
    Stream* self;
    void (*readFunction)();
    void (*writeFunction)();
    void (*seekFunction)();
    void (*closeFunction)();
    u8 padding[0x24];
    u32 cookie;
};

void func_00302c28(Stream* stream, u32 mode, u32 descriptor, u32 cookie) {
    stream->cookie = cookie;
    stream->mode = mode;
    stream->descriptor = descriptor;
    stream->readFunction = func_00304de8;
    stream->writeFunction = D_00304e48;
    stream->field0 = 0;
    stream->field4 = 0;
    stream->field8 = 0;
    stream->seekFunction = func_00304ec8;
    stream->closeFunction = D_00304f30;
    stream->field10 = 0;
    stream->field14 = 0;
    stream->field18 = 0;
    asm volatile("" ::: "memory"); // why: keeps store order
    stream->self = stream;
}
