//第一次运行：生成三个迷宫，难度等级依次增高，箱子数量分别为1，2，3。将三个迷宫分别写入三个txt文档
//之后的运行：依次读取三个txt文档中的信息，打印迷宫，进行游戏
//箱子生成方式：采用深度优先遍历分别生成9*9，13*13，17*17的三个迷宫，再将开路扩宽至两格宽
//箱子起始点和终点？
//移动方式：再基础的asdw控制以外添加箱子移动判定，与箱子一起动
#include<stdio.h>

//全局变量
int mate_1[9][9],mate_2[13][13],mate_3[17][17];
int control_number;
int current_Line=1,current_Column=1;
//函数原型
void mate_intialization(int mate_size);
void mate_DepthFirstSearch(int current_line,int current_column,int mate_size);
//函数定义
void mate_intialization(int mate_size){//mate_size为9，13，17
    for(int i=0;i<mate_size;i++){
        for(int j=0;j<mate_size;j++){
            switch(mate_size){
                case 9:
                    if(i%2==1&&j%2==1){
                        mate_1[i][j]=1;
                    }
                    break;
                case 13:
                    if(i%2==1&&j%2==1){
                        mate_2[i][j]=1;
                    }
                    break;
                case 17:
                    if(i%2==1&&j%2==1){
                        mate_3[i][j]=1;
                    }
                    break;
            }
        }
    }
    switch (mate_size){
        case  9:mate_1[1][1]=2;break;
        case 13:mate_2[1][1]=2;break;
        case 17:mate_3[1][1]=2;break;
    }

}void DepthFristSearch(int current_line,int current_column,int mate_size){
    
}
int main(){

    return 0;
}