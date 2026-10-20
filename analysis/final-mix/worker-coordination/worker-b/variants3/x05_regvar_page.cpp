typedef unsigned int u32;
typedef unsigned char u8;
struct FmInitPair { u32 first, second; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48;
extern u32 D_004f3b38_raw[2];
extern "C" u32 sink_reg;

void func_00161410(u32 phase, u32 priority) {
    register u32 page asm("$14") = 0x004f0000u;
    if (priority == 0xffffu && phase == 1) {
        asm volatile("" : "+r"(page));
        D_004f3b38.first = 0;
        D_004f3b38.second = 0;
    }
    if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
}
