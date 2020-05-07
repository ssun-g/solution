#include<cstdio>
using namespace std;

int main() {
	char arr[1000];
	scanf("%s", &arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		arr[i] = (arr[i] - 3 < 'A') ? arr[i] + 26 - 3 : arr[i] - 3;
	}

	printf("%s\n", arr);
	return 0;
}