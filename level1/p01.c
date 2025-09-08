#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
int GetScreenWidth(){//获取控制台长度
    HANDLE hConsole =GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX csbi;
    csbi.cbSize=sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    const int WIDTH=csbi.srWindow.Right-csbi.srWindow.Left+1;
    return WIDTH;
}
void getletter(char Letter){//获取目标字符
    scanf("%c",&Letter);
    //clear_stdin_buffer();
    //fflush(stdin);
}
int direction_determination(int ruffered_Number){//决定移动方向
    if(ruffered_Number%2==0){
        return 1;//right forward
    }/*else{
        return 2;//left forward
    }*/
}
void moveletter(int move_Number,char Letter){//字符移动
    for(int i=0;i<move_Number-1;i++){
          puts("");
    }
    printf("%c",&Letter);
    system("CLS");
}
int main(){
    int move_number=1,ruffered_number=0;
    char letter;
    getletter(letter);
    while(1){
        moveletter(move_number,letter);
       // system("pause");
        if(move_number==GetScreenWidth()||move_number==0){
            ruffered_number++;
        }
        if(direction_determination(ruffered_number)==1){
            move_number++;
        }else{
            move_number--;
        }
        
    }
    return 0;
}
/*
1 获取控制台长度
2 获取字符
3 循环
    确定方向
    空格数
    字符
    清屏
*/