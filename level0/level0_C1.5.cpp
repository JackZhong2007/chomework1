#include<stdio.h>
int size_Compare(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	int num_a, num_b, num_c;
	scanf_s("%d%d%d", &num_a, &num_b, &num_c);
	printf("%d",size_Compare( size_Compare(num_a, num_b),num_c));
	return 0;
}