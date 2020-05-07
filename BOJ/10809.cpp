#include<cstdio>
using namespace std;

char arr[100];
int alp[26];

int main() {
	int i = 0;
	scanf("%s", arr);
	for (int j = 0; j < 26; j++) {
		alp[j] = -1;
	}
	while (true) {
		if (arr[i] == '\0') break;
		if (alp[(int)arr[i] - 'a'] == -1)
			alp[(int)arr[i] - 'a'] = i;
		i++;
	}

	for (int j = 0; j < 26; j++) {
		printf("%d ", alp[j]);
	}

	return 0;
}