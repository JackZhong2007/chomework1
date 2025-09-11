//0为墙壁，1为开路，2为人物，3为箱子，4为目标点
#include<stdio.h>
int main(){
    FILE *file;
    char a[234];
    file=fopen("test.txt","r");
    if(file==NULL){
        printf("fail");
    }
    while(fgets(a,sizeof(a),file)!=NULL){
        printf("%s",a);
    }
    fclose (file);
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    FILE *file;
    char filename[100];
    int array[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;
    int i, j;
    char ch;

    // 获取文件名
    printf("请输入文件名: ");
    scanf("%s", filename);

    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 1;
    }

    // 读取二维数组
    while (rows < MAX_ROWS && !feof(file)) {
        cols = 0;
        // 读取一行数据
        while (cols < MAX_COLS && fscanf(file, "%d", &array[rows][cols]) == 1) {
            cols++;
        }
        
        // 检查是否读取到了数据
        if (cols > 0) {
            rows++;
        }
        
        // 跳过行尾的换行符
        while ((ch = fgetc(file)) == '\n' || ch == ' ' || ch == '\t');
        if (ch != EOF) ungetc(ch, file);
    }

    // 关闭文件
    fclose(file);

    // 打印二维数组
    printf("读取到的二维数组:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}*/