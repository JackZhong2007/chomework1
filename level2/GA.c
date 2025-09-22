//0 is wall;1 is node;2 is can be chosen road;3 is road;4 is can not be chosen raod
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define ORIGIN_LINE 1;
#define ORIGIN_COLUMN 1;
int mate[25][101];
int can_be_chosen_number;
int flagmax;

void mate_initialization();
void print_mate();
void generate_canBeChosen_road(int line,int column);
void generate_mate();

void mate_initialization(){
    for(int i=0;i<=24;i++){
        for(int j=0;j<=100;j++){
            if(i%2==1&&j%2==1){
                mate[i][j]=1;
                flagmax++;
            }else{
                mate[i][j]=0;
            }
        }
    }
    mate[1][1]=3;
    generate_canBeChosen_road(1,1);
}
void print_mate(){
    for(int i=0;i<=24;i++){
        for(int j=0;j<=100;j++){
            if(mate[i][j]==3){
                printf(" ");
            }else{
                printf("%d",mate[i][j]);
            }
            
        }
        printf("\n");
    }
}
void generate_canBeChosen_road(int line,int column){
    if(mate[line-1][column]==0&&line>1){
        mate[line-1][column]=2;
        can_be_chosen_number++;
    }
    if(mate[line+1][column]==0&&line<23){
        mate[line+1][column]=2;
        can_be_chosen_number++;
    }
    if(mate[line][column-1]==0&&column>1){
        mate[line][column-1]=2;
        can_be_chosen_number++;
    }
    if(mate[line][column+1]==0&&column<99){
        mate[line][column+1]=2;
        can_be_chosen_number++;
    }
}
int randseed[5],size;
void generate_mate(){//0 is left;1 is right;2 is up;3 is down
    //generate_canBeChosen_road(line,column);
    int position=rand()%can_be_chosen_number;
    randseed[size]=position;size++;
    int find_position=0;
    for(int i=0;i<=24;i++){
        for(int j=0;j<=100;j++){
            if(mate[i][j]==2){
                find_position++;
                if(find_position==position+1){
                    bool flag=false;
                    if(mate[i][j-1]==1){
                        mate[i][j-1]=3,mate[i][j]=3;
                        can_be_chosen_number--;
                        flag=true;
                        flagmax--;
                        generate_canBeChosen_road(i,j-1);
                        generate_mate();
                    }else if(mate[i][j+1]==1){
                        mate[i][j+1]=3,mate[i][j]=3;
                        can_be_chosen_number--;
                        flag=true;
                        flagmax--;
                        generate_canBeChosen_road(i,j+1);
                        generate_mate();
                    }else if(mate[i-1][j]==1){
                        mate[i-1][j]=3,mate[i][j]=3;
                        can_be_chosen_number--;
                        flag=true;
                        flagmax--;
                        generate_canBeChosen_road(i-1,j);
                        generate_mate();
                    }else if(mate[i+1][j]==1){
                        mate[i+1][j]=3,mate[i][j]=3;
                        can_be_chosen_number--;
                        flag=true;
                        flagmax--;
                        generate_canBeChosen_road(i+1,j);
                        generate_mate();
                    }
                    if(!flag){
                        generate_mate();
                    }
                }
            }
        }
    }
}
int main(){
    srand((unsigned)time(NULL));
    mate_initialization();
    //while(flagmax>0){
        generate_mate();
    //}
    print_mate();
    printf("\n%d\n",can_be_chosen_number);
    for(int i=0;i<5;i++){
        printf("%d\t",randseed[i]);
    }
    printf("\n%d",mate[0][0]);
    return 0;
}