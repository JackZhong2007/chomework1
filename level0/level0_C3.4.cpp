#include<stdio.h>
void judge_RT(int side[]) {
	for (int i = 1; i < 3; i++) {
		if (side[0] < side[i]) {
			side[0] = side[0] ^ side[i];
			side[i] = side[0] ^ side[i];
			side[0] = side[0] ^ side[i];
		}
	}
	if (side[0]*side[0] == side[1]*side[1] + side[2]*side[2]) {
		printf("This triangle is a rhigt triangle");
	}
	else {
		printf("This triangle is not a right triangle");
	}
}
int main() {
	int side_triangle[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &side_triangle[i]);
	}
	judge_RT(side_triangle);
	return 0;
}