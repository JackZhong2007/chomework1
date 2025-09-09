#include<stdio.h>
#include<math.h>
void print(int situation){
    switch(situation){
        case  1:printf("A->B\n");  break;
        case  2:printf("A->C\n");  break;
        case  3:printf("B->C\n");  break;
        case -1:printf("B->A\n");  break;
        case -2:printf("C->A\n");  break;
        case -3:printf("C->B\n");  break;
    }
}
typedef struct{
    int n;
    int situation;
    int reversal;
}aaa;
void hanoi(int n,int reversal){
    //int reversal_number=pow(2,n-1);
    int reversal_number=1;
    if(n==1){
        //print(1);
        if(reversal==0){
            print(1);reversal_number++;
        }else{
            if(reversal_number==1||reversal_number==pow(2,n-2)+1){
                print(-1);reversal_number++;
            }else{
                print(1);reversal_number++;
            }
        }
    }else if(n==2){
        //print(2);print(3);
        if(reversal==0){
            print(2);reversal_number++;
        }else{
            if(reversal_number==1||reversal_number==pow(2,n-2)+1){
                print(-2);reversal_number++;
            }else{
                print(2);reversal_number++;
            }
        }
        //
        if(reversal==0){
            print(3);reversal_number++;
        }else{
            if(reversal_number==1||reversal_number==pow(2,n-2)+1){
                print(-3);reversal_number++;
            }else{
                print(3);reversal_number++;
            }
        }
    }else if(n>2){
        hanoi(n-2,0),hanoi(n-1,1),hanoi(n-2,0);
    }
}
int main(){
    hanoi(4,0);
    return 0;
}