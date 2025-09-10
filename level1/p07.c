//待办事宜
//1迷宫初始化 1 0赋值 完成
//2迷宫路线生成
//3移动控制
//4碰壁以及成功设置

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<Windows.h>

//0为闭路 1为迷宫路线生成点 2为开路 3为 4为终点 5为

//全局变量
int mate[21][21];
//函数原型
int move(char keyboard);//未完成
void mate_intialization();
void mate_maker_routeplan(int random_direction,int current_line,int current_column);
void mate_maker(int current_line,int current_column);
//函数
/*int move(char keyboard){
    switch (keyboard){
        case 'a' : 
    }
}*/
int move(char keyboard)
{
    return 0;
}
void mate_intialization(){
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            if(i%2==1&&j%2==1){
                mate[i][j]=1;
            }else{
                mate[i][j]=0;
            }
        }
    }
    mate[1][1]=2;//简单化处理：令【1】【1】为迷宫入口
}
void mate_maker_routeplan(int random_direction,int current_line,int current_column){
   //srand((unsigned)time(NULL));
    switch(random_direction){
        case 0://下
            if(current_line<=17){
                if(mate[current_line+2][current_column]==1){
                    mate[current_line+2][current_column]=2,mate[current_line+1][current_column]=2;
                   //srand((unsigned)time(NULL));
                    mate_maker(current_line+2,current_column);
                    return ;
                }else{
                    return ;
                }
            }else{
                return ;
            }
            break;
        case 1://右
            if(current_column<=17){
                if(mate[current_line][current_column+2]==1){
                    mate[current_line][current_column+2]=2,mate[current_line][current_column+1]=2;
                   //srand((unsigned)time(NULL));
                    mate_maker(current_line,current_column+2);
                    return ;
                }else{
                    return ;
                }
            }else{
                return ;
            }
            break;
        case 2://上
            if(current_line>=3){
                if(mate[current_line-2][current_column]==1){
                    mate[current_line-2][current_column]=2,mate[current_line-1][current_column]=2;
                   //srand((unsigned)time(NULL));
                    mate_maker(current_line-2,current_column);
                    return ;
                }else{
                    return ;
                }
            }else{
                return ;
            }
            break;
        case 3://左
            if(current_column>=3){
                if(mate[current_line][current_column-2]==1){
                    mate[current_line][current_column-2]=2,mate[current_line][current_column-1]=2;
                   //srand((unsigned)time(NULL));
                    mate_maker(current_line,current_column-2);
                    return ;
                }else{
                    return ;
                }
            }
            else{
                return ;
            }
            break;
    }
}
void mate_maker(int current_line,int current_column){
    //srand((unsigned)time(NULL));
    //int random_direction=rand()%4;//0为下 1为右 2为上 3为上
    while(1){
        //srand((unsigned)time(NULL));
        int random_direction=rand()%4;
        if((mate[current_line-2][current_column]==1||mate[current_line+2][current_column]==1||mate[current_line][current_column+2]==1||mate[current_line][current_column-2]==1)==0){
            return ;
        }else{
            mate_maker_routeplan(random_direction,current_line,current_column);
            /*if(1==a){
                switch(random_direction){
                    case 0:current_line+=2;break;
                    case 1:current_column+=2;break;
                    case 2:current_line-=2;break;
                    case 3:current_line-=2;break;
                }
            }*/
        }
    }
}
int main(){
    srand((unsigned)time(NULL));
    mate_intialization();
    mate_maker(1,1);
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            printf("%d ",mate[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                printf("%d ",mate[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        system("pause");*/