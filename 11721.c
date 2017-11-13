#include<stdio.h>

int main() {
	int i = 0;
	char arr[100];
	scanf("%s", arr);

	while (arr[i]) {
		printf("%c", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
		i++;
	}

	return 0;
}
