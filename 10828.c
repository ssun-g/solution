#include<stdio.h>
#include<string.h>

int a, stack[10001];

int main() {
	int n, cnt = 0;
	char str[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &a);
			if (stack[0] == 0) {
				stack[0] = a;
			}
			else {
				for (int i = 0; i < 10001; i++) {
					if (stack[i] == 0) {
						stack[i] = a;
						break;
					}
				}
			}
		}
		if (strcmp(str, "pop") == 0) {
			int i = 0;
			if (stack[0] == 0)
				printf("-1\n");
			else {
				for (i = 0; i < 10001; i++) {
					if (stack[i] == 0) {
						printf("%d\n", stack[i - 1]);
						stack[i - 1] = 0;
						break;
					}
				}
			}
		}
		if (strcmp(str, "size") == 0) {
			for (int i = 0; i < 10001; i++) {
				if (stack[i] != 0)
					cnt++;
			}
			printf("%d\n", cnt);
			cnt = 0;
		}
		if (strcmp(str, "empty") == 0) {
			if (stack[0] == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if (strcmp(str, "top") == 0) {
			int i = 0;
			if (stack[0] == 0)
				printf("-1\n");
			else {
				for (i = 0; i < 10001; i++) {
					if (stack[i] == 0) {
						printf("%d\n", stack[i - 1]);
						break;
					}
				}
			}
		}
	}
	return 0;
}