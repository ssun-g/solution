#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char arr[50][50];

int Candy() {
	int result = 1;
	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j - 1] == arr[i][j]) temp++;
			else {
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 1; j < n; j++) {
			if (arr[j - 1][i] == arr[j][i]) temp++;
			else {
				result = max(result, temp);
				temp = 1;
			}
		}
		result = max(result, temp);
	}

	return result;
}

int main() {
	int MAX = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			MAX = max(MAX, Candy());
			swap(arr[i][j], arr[i][j + 1]);

			swap(arr[j][i], arr[j + 1][i]);
			MAX = max(MAX, Candy());
			swap(arr[j][i], arr[j + 1][i]);
		}
	}
	printf("%d\n", MAX);

	return 0;
}