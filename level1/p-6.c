#include<stdio.h>
#include<math.h>
void hanoi(int number,int currentNumber,char from,char target,char blank){
    printf("%c->%c\n",from,target);
    number++;
    if(number<currentNumber){
        
    }
}
int main(){
    char a='A',b='B',c='C';
    /*for(int i=1;i<=64;i++){
        int number=0;
        if(i%2==1){
            hanoi(number,i,a,b,c);
        }else{
            hanoi(number,i,a,c,b);
        }
    }*/
    for(int i=1;i<65;i++){
        for(int j=1;j<pow(2,i-1);j++){

        }
    }
    return 0;
}