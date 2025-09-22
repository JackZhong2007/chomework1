#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct {
    int*data;
    int front,count;
    int capacity;
}Queue;
Queue*create_queue(int capacity){
    Queue*queue=(Queue*)malloc(sizeof(Queue));
    queue->data=(int*)malloc(sizeof(int)*capacity);
    queue->front=0;
    queue->count=0;
    queue->capacity=capacity;
    return queue;
}
void push(Queue*queue,int value){
    queue->data[queue->front+queue->count]=value;
    queue->count++;
}
int pop(Queue*queue){
    int temp=queue->data[queue->front+queue->count-1];
    queue->data[queue->front+queue->count]=0;
    queue->count--;
    return temp;
}
int main(){
    Queue*queue=create_queue(10);
    push(queue,1);
    push(queue,2);
    int x=pop(queue);
    int u=pop(queue);
    assert(x==2);
    assert(u==1);
    printf("%d\n",queue->count);
    return 0;
}
/*int queue[100];
int index;
void inQueue(int number){
    int i=0;
    while(1){
        if(queue[i]==0){
            queue[i]=number;
            return ;
        }else{
            i++;
        }
    }
}
/*
int outQueue(){
    int j=queue[0],i=0;
    do{
        queue[i]=queue[i+1];
        i++;
    }while(queue[i]==0);
    return j;
}
int outQueue(){
    int remain=queue[index];
    queue[index]=0;
    index++;
    if(index=100){
        index=0;
    }
    return remain;
}
bool Is_empty(){

}
*/


    /*inQueue(1);
    inQueue(2);
    int x=outQueue();
    //printf("%d\n%d",x,queue[0]);
    //assert(x==2);用鸿进行调试
    int a;
    int *b=&a;
    2[b];
    b[2];*/
/*
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct{
    int *data;
    int front,count;
    int capacity;
}Queue;
Queue* creat_queue(int capacity){
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q->capacity=capacity;
    q->front=0;
    q->count=0;
    q->data=(int*)malloc(sizeof(int)*capacity);
    return q;
}
void push(Queue*queue,int value){
    //queue->count++;
    queue->data[queue->front+queue->count++]=value;
    //处理回转 未完成

}
int pop(Queue*queue){
    int value=queue->data[queue->front++];
    queue->count--;
    //处理翻转
    return value;
}
int main(){
    Queue* q1=creat_queue(100);
    assert(q1!=NULL);
    assert(q1->data!=NULL);
    assert(q1->capacity>0);
    push(q1,1);
    push(q1,2);

    int x=pop(q1);
    assert(x==1);
    int y=pop(q1);
    assert(y==2);
    return 0;
}
    */