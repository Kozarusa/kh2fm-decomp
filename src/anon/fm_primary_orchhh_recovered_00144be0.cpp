#include "../common/types.h"
extern "C" f32 D_0036af68[];

void func_00144be0(f32* box, f32* corners) {
    f32* source = D_0036af68;
    asm("" : "+r"(source)); // why: original materializes the full address before the load
    f32 one = *source;
    corners[31] = one;
    corners[27] = one;
    corners[23] = one;
    corners[19] = one;
    corners[15] = one;
    corners[11] = one;
    corners[7] = one;
    corners[3] = one;
    corners[0] = box[0];
    corners[1] = -box[4];
    corners[2] = -box[5];
    corners[4] = box[0];
    corners[5] = -box[1];
    corners[6] = -box[5];
    corners[8] = box[3];
    corners[9] = -box[1];
    corners[10] = -box[5];
    corners[12] = box[3];
    corners[13] = -box[4];
    corners[14] = -box[5];
    corners[16] = box[0];
    corners[17] = -box[4];
    corners[18] = -box[2];
    corners[20] = box[0];
    corners[21] = -box[1];
    corners[22] = -box[2];
    corners[24] = box[3];
    corners[25] = -box[1];
    corners[26] = -box[2];
    corners[28] = box[3];
    corners[29] = -box[4];
    corners[30] = -box[2];
}
