#include<stdio.h>

int Com(int);

int main(void) {
	int n1, n2;
	scanf("%d", &n1);

	for (int i = 0; i < n1; i++) {
		scanf("%d", &n2);
		printf("%d\n", Com(n2));
	}
	return 0;
}

int Com(int num) {
	if (num == 1) return 1;
	else if (num == 2) return 2;
	else if (num == 3) return 4;
	else return Com(num - 1) + Com(num - 2) + Com(num - 3);
}