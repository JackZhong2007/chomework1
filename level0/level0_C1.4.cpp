#include<stdio.h>
void size_Comparision( int a, int b) {
	if (a > b) {
		printf("The bigger one is %d !",int(a) );
	}
	else if (a < b) {
		printf("The bigger one is %d !", int(b));
	}
	else {
		printf("There is no winner!");
	}
}
int main() {
	int num_a, num_b;
	scanf_s("%d%d", &num_a, &num_b);
	size_Comparision(num_a, num_b);
	return 0;
}