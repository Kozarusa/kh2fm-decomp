#include "../common/types.h"

void func_0020ea48(u32 first,u32 second,u32 third) {
    register u32 high asm("$14")=0x360000;
    asm volatile("" : "+r"(high), "+r"(first));
    first&=0xff; asm volatile("" : "+r"(first));
    *(u8*)(high-0x6eb0)=first; asm volatile("" ::: "memory", "$15");
    register u8* base asm("$15");
    asm volatile("addiu %0,%1,-0x6eb0" : "=r"(base) : "r"(high) : "memory");
    asm volatile("" : "+r"(base), "+r"(second), "+r"(third) :: "memory");
    second&=0xff; third&=0xff;
    asm volatile("" : "+r"(second), "+r"(third));
    base[2]=third; asm volatile("" ::: "memory"); base[1]=second;
}

void func_001e1df8(u8* object) {
    register u32 high asm("$15")=0x370000;
    asm volatile("" : "+r"(high));
    register f32 current asm("$f1")=*(f32*)(object+0xde4);
    asm volatile("" : "+f"(current));
    register f32* source asm("$15")=(f32*)(high-0x16d8);
    asm volatile("" : "+r"(source));
    register f32 threshold asm("$f0")=*source;
    asm volatile("" : "+f"(threshold));
    if(threshold<=current) {
        high=0x370000; asm volatile("" : "+r"(high));
        *(u32*)(object+0xde8)=0; asm volatile("" : "+r"(high) :: "memory");
        source=(f32*)(high-0x16d4); asm volatile("" : "+r"(source));
        *(u32*)(object+0xdfc)=0; asm volatile("" ::: "memory");
        register f32 value asm("$f0")=*source;
        asm volatile("" : "+f"(value));
        *(u32*)(object+0xde4)=0; asm volatile("" ::: "memory");
        register u32 state asm("$15")=4; asm volatile("" : "+r"(state));
        *(f32*)(object+0xdf8)=value; asm volatile("" ::: "memory");
        *(u32*)(object+0xdc0)=state;
        asm volatile(".set push; .set noreorder; swc1 %0,0xdf4(%1); .set pop"
                     :: "f"(value), "r"(object) : "memory");
    }
}

void func_0031e268(u8* cursor) {
    register u32 high asm("$15")=0x370000;
    asm volatile("" : "+r"(high));
    cursor+=4; asm volatile("" : "+r"(cursor), "+r"(high));
    register f32* source asm("$15")=(f32*)(high-0x3dc8);
    asm volatile("" : "+r"(source));
    register s32 count asm("$14")=7;
    asm volatile("" : "+r"(count));
    register f32 value asm("$f0")=*source;
    asm volatile("" : "+f"(value));
    register s32 limit asm("$13")=-1;
    register u32 byte_value asm("$15")=0x80;
    asm volatile("" : "+r"(limit), "+r"(byte_value));
    do {
        *(u32*)(cursor-4)=0;
        --count;
        cursor[0]=byte_value; cursor[1]=byte_value;
        cursor[2]=byte_value; cursor[3]=byte_value;
        *(f32*)(cursor+4)=value;
        *(u32*)(cursor+8)=0;
        cursor+=0x10;
    } while(count!=limit);
}

void func_002be2d8(u8* object,u32 index,const f32* data) {
    register u32 scaled asm("$5")=index*4;
    register f32 first asm("$f1")=data[0];
    asm volatile("" : "+r"(scaled), "+f"(first));
    register u8* entry asm("$5")=object+scaled;
    asm volatile("" : "+r"(entry));
    register f32 third asm("$f3")=data[2];
    asm volatile("" : "+f"(third));
    register u8* target asm("$14")=*(u8**)(entry+0x2c);
    asm volatile("" : "+r"(target));
    register f32 second asm("$f2")=data[1];
    asm volatile("" : "+f"(second));
    *(f32*)(target+0x220)=first; asm volatile("" : "+r"(target) :: "memory");
    register f32* output asm("$15")=(f32*)(target+0x220);
    asm volatile("" : "+r"(output));
    output[1]=second;
    register u32 high asm("$14")=0x370000;
    asm volatile("" : "+r"(high));
    output[2]=third; asm volatile("" : "+r"(high) :: "memory");
    register f32* source asm("$14")=(f32*)(high+0x4fe0);
    asm volatile("" : "+r"(source));
    register f32 fourth asm("$f0")=*source;
    asm volatile("" : "+f"(fourth));
    output[3]=fourth;
}
