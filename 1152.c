#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int cnt = 0;
	int i = 0;
	char *arr = (char *)malloc(sizeof(char) * 1000001);

	scanf("%[^\n]s", arr);

	while (arr[i]) {
		if (arr[i] == ' ' && arr[i + 1] != ' ')
			cnt++;
		i++;
	}

	if (arr[0] == ' ')
		cnt--;
	if (arr[strlen(arr) - 1] == ' ')
		cnt--;

	printf("%d", cnt + 1);
	free(arr);
	return 0;
}