#include "../common/types.h"

void func_00144be0(f32* box, f32* corners) {
    corners[31] = 1.0f;
    corners[27] = 1.0f;
    corners[23] = 1.0f;
    corners[19] = 1.0f;
    corners[15] = 1.0f;
    corners[11] = 1.0f;
    corners[7] = 1.0f;
    corners[3] = 1.0f;
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
