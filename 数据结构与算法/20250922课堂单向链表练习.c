#include<stdio.h>
#include<stdlib.h>
typedef struct SLLIST{
    int data;
    struct SLLIST*point;
}SLLIST;
SLLIST*create_head_node(SLLIST*head_node){
    head_node=(SLLIST*)malloc(sizeof(SLLIST));
    head_node->point=NULL;
    return head_node;
}
SLLIST*create_node(int data){
    SLLIST*new_node=(SLLIST*)malloc(sizeof(SLLIST));
    new_node->data=data;
    new_node->point=NULL;
    return new_node;
}
void head_insert(SLLIST*head_node,int data){
    SLLIST*new_node=create_node(data);
    new_node->point=head_node->point;
    head_node->point=new_node;
}
void append(SLLIST*head_node,int data){
    SLLIST*new_node=create_node(data);
    new_node->point=NULL;
    if(head_node->point==NULL){
        head_node->point=new_node;
        return ;
    }
    SLLIST*now_node=head_node->point;
    while(now_node->point){
        now_node=now_node->point;
    }
    now_node->point=new_node;
}
void print_singly_linked_list(SLLIST*head_node){
    if(head_node->point==NULL){
        printf("This singly linked list is empty.\n");
        return ;
    }
    SLLIST*now_node=head_node->point;
    while(now_node->point){
        printf("%d\t",now_node->data);
        now_node=now_node->point;
    }
    printf("%d\n",now_node->data);
}
int main(){
    SLLIST*head_node=create_head_node(head_node);
    head_insert(head_node,1);
    head_insert(head_node,2);
    append(head_node,3);
    print_singly_linked_list(head_node);
    return 0;
}