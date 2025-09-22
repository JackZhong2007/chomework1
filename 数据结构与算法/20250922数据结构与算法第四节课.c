#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char*data;
    int front,count;
    int capacity;
}Queue;
Queue*create_queue(int capacity){
    Queue*queue=(Queue*)malloc(sizeof(Queue));
    queue->data=(char*)malloc(sizeof(char)*capacity);
    queue->front=0;
    queue->count=0;
    queue->capacity=capacity;
    return queue;
}
void push(Queue*queue,char value){
    queue->data[queue->front+queue->count]=value;
    queue->count++;
}
char pop(Queue*queue){
    char temp=queue->data[queue->front+queue->count-1];
    queue->data[queue->front+queue->count]=0;
    queue->count--;
    return temp;
}
int main(){
    
    char nbl[100];
    gets(nbl);
    Queue*queue=create_queue(sizeof(nbl));
    for(int i=0;i<sizeof(nbl);i++){
        push(queue,nbl[i]);
    }
    printf("%s",nbl);
    return 0;
}
/*char* nibolan[100];
    scanf("%s",&nibolan);
    int conclusion=0;
    int length=sizeof(nibolan);
    for(int i=0;i<length;i++){
        int a=0;
        if(nibolan[i]==','){
            if(nibolan[i+2]=='+'){
                a=(int)nibolan[i-1]+(int)nibolan[i+1];
            }else if(nibolan[i+2]=='-'){
                a=(int)nibolan[i-1]-(int)nibolan[i+1];
            }
            
        }
        conclusion+=a;
    }
    printf("%d",conclusion);
    printf("%s",nibolan);*/