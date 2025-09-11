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
}