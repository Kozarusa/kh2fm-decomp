#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Request { u8* object; f32 value; u32 flag; };
extern "C" Quad D_01c5f480;
extern "C" void func_00185138(u32,Quad*,bool,f32);

void func_00171640(Request* record)
{
    Quad* destination = &D_01c5f480;
    func_00185138(*(u32*)(record->object + 4), destination, record->flag != 0, record->value);
    record->object = (u8*)destination;
}
