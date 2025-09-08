#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>
int main(){
    LARGE_INTEGER time_start;
    LARGE_INTEGER time_over;
    LARGE_INTEGER frequency;
    QueryPerformanceCounter(&time_start);
    QueryPerformanceFrequency(&frequency);
    bool prime_number[1001];
    for(int i=2;i<1001;i++){
        prime_number[i]=true;
    }
    int previous_PRIMENUMBER[1001]={0},prenumber=0;
    for(int i=2;i<=1000;i++){
        if(prime_number[i]){
            previous_PRIMENUMBER[prenumber]=i;
            prenumber++;
        }
        for(int j=0;j<prenumber&&i*previous_PRIMENUMBER[j]<1001;j++){
            prime_number[i*previous_PRIMENUMBER[j]]=false;
            if(i%previous_PRIMENUMBER[j]==0){
                goto next;
            }
        }
        next: ;
    }
    for(int i=2;i<1001;i++){
        if(prime_number[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    QueryPerformanceCounter(&time_over);
    float time_in_micro=1000000.0*(time_over.QuadPart-time_start.QuadPart)/frequency.QuadPart;
    printf("The running time:%fmicroseconds",time_in_micro);
    return 0;
}