#include<cstdio>
using namespace std;

char arr[20];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		scanf("%s", arr);
		for (int j = 0; arr[j] != '\0'; j++) {
			for (int k = 0; k < n; k++) {
				printf("%c", arr[j]);
			}
		}
		printf("\n");
	}

	return 0;
}