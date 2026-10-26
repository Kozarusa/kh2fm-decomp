#include "../common/types.h"
struct __attribute__((packed,aligned(2))) Record { u8 bytes[8]; s16 second; };
extern "C" Record D_0032bae0,D_0032bb10;
extern "C" void func_0019ee80(u32,u32);
extern "C" void func_001d5198(Record*);

void func_00178220(void)
{
    func_0019ee80(D_0032bae0.bytes[0], D_0032bae0.bytes[1]);
    D_0032bb10 = D_0032bae0;
    func_001d5198(&D_0032bae0);
}
