#include<cstdio>
using namespace std;

int main() {
	int cmp1, cmp2;
	int a_len = 0, b_len = 0, cnt = 0;
	char arr1[31], arr2[31];
	bool flag = false;
	scanf("%s%s", arr1, arr2);

	while (true) {
		if (arr1[a_len] == '\0')
			break;
		a_len++;
	}
	while (true) {
		if (arr2[b_len] == '\0')
			break;
		b_len++;
	}
	for (int i = 0; i < a_len; i++) {
		if (flag) break;
		for (int j = 0; j < b_len; j++) {
			if (arr1[i] == arr2[j]) {
				flag = true;
				cmp1 = i;
				cmp2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < b_len; i++) {
		bool flag2 = false;
		if (i == cmp2) {
			printf("%s", arr1);
			flag2 = true;
		}
		for (int j = 0; j < a_len; j++) {
			if (flag2) {
				cnt++;
				flag2 = false;
			}
			if (i != cmp2) {
				if (j == cmp1) {
					printf("%c", arr2[cnt++]);
				}
				else {
					printf(".");
				}
			}
		}
		printf("\n");
	}

	return 0;
}