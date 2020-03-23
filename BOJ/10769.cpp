#include<cstdio>
#include<algorithm>
using namespace std;

int h_cnt, s_cnt;
char arr[256];

int main() {
	int i = 0;
	scanf("%[^\n]s", arr);
	while (arr[i] != '\0') {
		if (arr[i] == ':') {
			if (arr[i + 1] == '-') {
				if (arr[i + 2] == ')') {
					h_cnt++;
				}
				else if (arr[i + 2] == '(') {
					s_cnt++;
				}
			}
		}
		i++;
	}
	if (h_cnt > s_cnt) {
		printf("happy\n");
	}
	else if (h_cnt < s_cnt) {
		printf("sad\n");
	}
	else if (h_cnt == 0 && s_cnt == 0) {
		printf("none\n");
	}
	else if (h_cnt == s_cnt) {
		printf("unsure\n");
	}

	return 0;
}