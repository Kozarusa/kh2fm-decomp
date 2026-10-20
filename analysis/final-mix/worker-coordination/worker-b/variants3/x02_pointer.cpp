typedef unsigned int u32;
typedef unsigned char u8;
struct FmInitPair { u32 first, second; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48;
extern u32 D_004f3b38_raw[2];
extern "C" u32 sink_reg;

void func_00161410(u32 phase, u32 priority) {
    u32* p = (u32*)&D_004f3b38.first;
    u32* q = (u32*)&D_004f3b40.first;
    u32* r = (u32*)&D_004f3b48.first;
    if (priority == 0xffffu && phase == 1) { p[0] = 0; p[1] = 0; }
    if (priority == 0xffffu && phase == 1) { q[0] = 0; q[1] = 0; }
    if (priority == 0xffffu && phase == 1) { r[0] = 0; r[1] = 0; }
}
