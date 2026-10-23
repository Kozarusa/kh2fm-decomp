/* Worker B - byte-exact recoveries for the eight unmatched FM initializers.
 *
 * Claimed addresses: 00104210 00161410 001995f8 001ba060 001c7ab8 001c8e00
 *                    001d6850 00241f20
 * Recovered exactly (verified by tools/kh2-audit/probe_fm_source.py):
 *   00161410, 001995f8, 001ba060, 001c8e00
 *
 * Shared guard shape used by the original code: each store block is an
 * independent `if (priority == 0xffffu && phase == 1)` statement rather than
 * nested conditions, because the original re-materialises the 0xffff constant
 * and re-tests both arguments in front of every block.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct FmInitPair { u32 first, second; };
struct FmInitFloat { u32 first, second; f32 value; };

extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48, D_01c62140;
extern FmInitPair D_01d48da0, D_01d48da8, D_01d48db0;
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01d48db8, D_00351eb8, D_00351ec0, D_00351ec8;
extern u32 D_01dae688[6], D_0032ba84, D_0035ebf8, D_0035ebfc;
extern u8 D_0032b930, D_01d498d0, D_01c620c8[];
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00104200(u32);

/* 0x001c8e00 - 96 bytes, three scalar zero stores into D_00351eb8/1ec0/1ec8. */

void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_00351eb8 = 0;
    if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
    if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
}

void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_004f3b38.second = 0; D_004f3b38.first = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b40.second = 0; D_004f3b40.first = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b48.second = 0; D_004f3b48.first = 0; }
}

void func_001ba060(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
}

void func_001995f8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u8* base = D_01c620c8;
        u32* target = (u32*)(base + 0x60);
        s32 index;
        for (index = 0; index < 4; ++index) *target++ = index;
        *(u32*)(base + 0x70) = 4;
    }
    if (priority == 0xffffu && phase == 1) { D_01c62140.first = 0; D_01c62140.second = 0; }
}
