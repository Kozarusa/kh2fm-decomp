#include "../common/types.h"

extern "C" u64 func_00134258(void);
extern "C" void func_00133f20(void), func_00134730(u64,u64,u64,u64,u64);
extern "C" void func_00135cc8(u64,u64,u64), func_00135ad0(u64);
extern "C" void func_00102c18(u32,u32,void*);
extern "C" void func_00137250(void), func_0013d750(void);
extern u8 D_003493a0;
extern "C" void func_002362b0(u8*), func_002367c8(u8*);
extern "C" void func_00138988(void), func_00138de0(u64);
extern "C" void func_001391c8(u64,u32,u32), func_0013b128(u64);
extern "C" void func_00141778(u32,u16);
extern "C" void func_00143b88(u64,u64,u32*,u32*,u64);
extern "C" void func_0014a9a0(u8*,u64);
extern "C" void func_0014ace8(void), func_0014a988(void*);
extern "C" void func_00139948(u32), func_00139ba0(u32);
extern "C" void func_001399c0(u32), func_00139b28(u32);
extern "C" u8* func_00140df0(void);
extern "C" void func_00140e30(u8*,u32);
extern "C" u32 func_0016c3a8(u32,u32);
extern "C" void func_0014e098(u32), func_001024a8(u64), func_0014e0d8(void);
extern "C" u32* func_00102c80(void);
extern "C" void func_00102688(u32,u32,u32);
extern "C" void func_00170888(void), func_001badd8(void), func_001afaf0(u64);
extern "C" void func_001a9350(u8*), func_0016c358(u8*);
extern "C" f32 func_002f8ad0(f32,f32);
extern "C" void func_0017d0e8(f32), func_00188b68(u32,u32,bool);
extern u32 D_00348804, D_0034aa08, D_0034aa90, D_0034aa94;
extern u32 D_00349df4, D_00349df8, D_00349dfc, D_00349e00;
extern u8 D_0034c770, D_0034c771;
extern u32 D_0034c774, D_0034c778;
extern s32 D_0034c768, D_0034c76c;

void func_00127da0(u32* object) { (*(void (**)(u32*))(*object))(object); }

void func_00134dd0(u64 first,u64 second,u64 third) { func_00134730(third,second,first,0,0); }

void func_00135c50(u64 first,u64 second) { func_00135cc8(first,second,0); func_00135ad0(first); }

void func_00135ff0(u32* object) {
    object[3]=0;
    s32 count=31;
    do { object[4]=0; --count; object[5]=0; object+=2; } while(count>=0);
}

void func_00136fa8(void) { func_00102c18(1,300000,(void*)func_00137250); }

void func_00138698(u8* object) { func_002362b0(object+0x20); func_002367c8(object+0x20); }

void func_001390c0(u64 value) { func_00138988(); func_00138de0(value); }

void func_0013b1a0(u64 value) { func_001391c8(value,0x14b6,1); func_0013b128(value); }

void func_0013d798(void) { func_00102c18(1,100000,(void*)func_0013d750); }

void func_00143448(u16 value) { func_00141778(D_00348804,value); asm volatile("" : : : "memory"); }

void func_00147c78(u64 unused,u8* object) {
    register u8 a asm("$14")=object[0xe8];
    register u8 b asm("$13")=object[0xe9];
    register u8 c asm("$12")=object[0xea];
    register u8 d asm("$15")=object[0xeb];
    asm volatile("" : "+r"(a), "+r"(b), "+r"(c), "+r"(d));
    object[0xc]=a; asm volatile("" ::: "memory");
    object[0xf]=d; asm volatile("" ::: "memory");
    object[0xd]=b; asm volatile("" ::: "memory");
    object[0xe]=c;
}

void func_0014aa80(u8* object,u64 second,u8 third) { *(u32*)(object+0xf8)=1; asm volatile("" : : : "memory"); object[0xf4]=third; asm volatile("" : : : "memory"); *(u32*)(object+0xfc)=1; func_0014a9a0(object,second); }

void func_0014acf8(void) { func_0014ace8(); func_0014a988(&D_003493a0); }

void func_00154af0(u8* object) { object[0x3ce0]=1; func_00139948(6); func_00139ba0(6); }

void func_00154b18(u8* object) { object[0x3ce0]=0; func_001399c0(6); func_00139b28(6); }

void func_001586b8(void) { u8* object=func_00140df0(); *(u32*)(object+0x40)=8; func_00140e30(object,3); }

void func_00159700(void) { D_0034aa08=0; u8* object=func_00140df0(); *(u32*)(object+0x40)=5; }

void func_0015a8a0(void) { D_0034aa94=func_0016c3a8(D_0034aa90,0x40); }

void func_001617e8(u64 value) { func_0014e098(0xd8); func_001024a8(value); }

void func_001619e8(void) { u32* object=func_00102c80(); func_00102688(object[1],3,3); }

void func_00161ee8(void) { D_0034c770=0; D_0034c771=0; D_0034c774=0; D_0034c778=0; }

void func_00161f10(u64 value) { func_0014e0d8(); func_001024a8(value); }

void func_001623b0(void) { u32* object=func_00102c80(); func_00102688(object[1],5,5); }

void func_00169148(u64 value) { func_00170888(); func_001badd8(); func_001afaf0(value); }

void func_0016a328(u8* value) { func_001a9350(value+0x7a0); func_0016c358(value); }

void func_0016b010(u8* object,f32* data) { *(f32*)(object+0x66c)=func_002f8ad0(data[0],data[2]); }

u64 func_0016b040(u64 value,u8* object) { func_0017d0e8(*(f32*)(object+0x66c)); return value; }
