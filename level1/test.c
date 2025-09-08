#include<stdio.h>
#include<Windows.h>
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csbi;
	csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hConsole,&csbi);
    //以下为隐藏光标
    CONSOLE_CURSOR_INFO cursorinfo;
    GetConsoleCursorInfo(hConsole,&cursorinfo);
    //BOOL oringinalVisibility=cursorinfo.bVisible;
    cursorinfo.bVisible=FALSE;
    SetConsoleCursorInfo(hConsole,&cursorinfo);
    //printf("%d\n",csbi.srWindow.Right - csbi.srWindow.Left + 1);
	int number = 0;
    while (1) {
        printf("\r");//相较于cls清屏，用移动光标至行首的方法会更加连贯！
		for (int i = 0; i < number; i++) {
			printf(" ");
		}
		printf("S");
        fflush(stdout);
        Sleep(10);
		//system("cls");
		number++;
		if (number == csbi.srWindow.Right - csbi.srWindow.Left + 1) {
			break;
		}
	}
	return 0;
}
/*int number = 0;
while (1) {
		for (int i = 0; i < number; i++) {
			printf(" ");
		}
		printf("S");
		system("cls");
		number++;
		//if (number == csbi.srWindow.Right - csbi.srWindow.Left + 1) {
		//	break;
		//}
	}*/