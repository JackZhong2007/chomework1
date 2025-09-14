#include <stdio.h>

int main() {
    FILE *file; // 定义文件指针

    // 打开文件（"w" 表示以写入模式打开，文件不存在会创建）
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("无法打开文件！\n");
        return 1; // 返回错误码
    }

    // 写入内容到文件
    fprintf(file, "Hello, World!\n");
    fprintf(file, "这是一个测试文件。\n");

    // 关闭文件
    fclose(file);
    return 0;
}//

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    FILE *file;
    char filename[100];
    int rows, cols;
    int array[MAX_ROWS][MAX_COLS];
    
    // 获取文件名
    printf("请输入要读取的文件名: ");
    scanf("%s", filename);
    
    // 获取数组的行数和列数
    printf("请输入数组的行数: ");
    scanf("%d", &rows);
    printf("请输入数组的列数: ");
    scanf("%d", &cols);
    
    // 检查输入是否有效
    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("错误: 行数和列数必须在1到%d之间\n", MAX_ROWS);
        return 1;
    }
    
    // 打开文件
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("错误: 无法打开文件 %s\n", filename);
        return 1;
    }
    
    // 读取文件内容到二维数组
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d", &array[i][j]) != 1) {
                printf("错误: 文件中的数据不足或格式错误\n");
                fclose(file);
                return 1;
            }
        }
    }
    
    // 关闭文件
    fclose(file);
    
    // 打印读取的数组
    printf("\n从文件中读取的数组内容:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}