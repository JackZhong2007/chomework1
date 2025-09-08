#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
int main(){
    LARGE_INTEGER time_start;
    LARGE_INTEGER time_over;
    LARGE_INTEGER frequency;
    QueryPerformanceCounter(&time_start);
    QueryPerformanceFrequency(&frequency);
    bool primeNumber[1001];
    for(int i=0;i<1001;i++){
        primeNumber[i]=true;
    }
    for(int i=2;i*i<=1000;i++){
        if(primeNumber[i]){
            for(int j=i*i;j<=1000;j+=i){
                primeNumber[j]=false;
            }
        }
    }
    for(int i=2;i<=1000;i++){
        if(primeNumber[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    QueryPerformanceCounter(&time_over);
    float time_in_micro=1000000.0*(time_over.QuadPart-time_start.QuadPart)/frequency.QuadPart;
    printf("The running time:%f microseconds",time_in_micro);
    return 0;
}