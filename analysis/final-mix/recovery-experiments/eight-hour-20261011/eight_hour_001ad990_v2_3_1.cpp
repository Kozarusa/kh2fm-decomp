void func_001ad990(float start,float end,float duration,float* output)
{
 register float zero asm("$f0")=0.0f;
 if(!(zero<duration)){
 (*(volatile float*)(output+1))=zero;
 (*(volatile float*)output)=end;
 asm("" : "+f"(zero) : "r"(output));
 return;
 }
 float difference=end-start;
 output[0]=start;
 output[1]=difference/duration;
}
