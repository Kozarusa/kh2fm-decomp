typedef unsigned int u32;
struct Pair { u32 first, second; };
extern Pair D_004f3b38, D_004f3b40, D_004f3b48;
extern Pair D_01d48da0, D_01d48da8, D_01d48db0;
extern u32 D_01d48db8, D_00351eb8, D_00351ec0, D_00351ec8;
extern "C" void v_00161410_0(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_1(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_2(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_3(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_4(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_5(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_6(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_7(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_8(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_00161410_9(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_10(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_00161410_11(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_12(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_13(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_14(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_15(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_16(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_17(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_18(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_00161410_19(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_20(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_00161410_21(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_00161410_22(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_00161410_23(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_004f3b38.first = 0; D_004f3b38.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_24(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_25(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_26(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_27(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_28(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_29(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_30(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_31(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_32(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001ba060_33(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_34(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001ba060_35(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_36(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_37(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_38(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_39(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_40(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_41(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_42(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001ba060_43(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_44(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001ba060_45(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001ba060_46(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001ba060_47(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_01d48da0.first = 0; D_01d48da0.second = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_01d48db8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_48(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_49(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_50(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_51(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_52(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_53(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_54(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_55(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_56(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001c8e00_57(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_58(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001c8e00_59(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) { D_00351eb8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_60(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_61(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_62(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_63(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_64(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_65(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_66(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm("" : "+r"(phase), "+r"(priority));
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority));
}

extern "C" void v_001c8e00_67(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm("" : "+r"(phase), "+r"(priority)); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_68(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001c8e00_69(u32 phase, u32 priority) {
if (priority == 0xffffu && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == 0xffffu && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}

extern "C" void v_001c8e00_70(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory");
}

extern "C" void v_001c8e00_71(u32 phase, u32 priority) {
register u32 limit asm("$15") = 0xffffu;
asm("" : "+r"(limit));
if (priority == limit && phase == 1) {
D_00351eb8 = 0;
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec0 = 0; }
}
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
if (priority == limit && phase == 1) { D_00351ec8 = 0; }
asm volatile("" : "+r"(phase), "+r"(priority) : : "memory"); asm volatile("" ::: "$15");
}
