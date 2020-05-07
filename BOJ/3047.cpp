#include<cstdio>
#include<algorithm>
using namespace std;

int arr[3];
char carr[3];

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%s", carr);

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++) {
		if (carr[i] == 'A') printf("%d ", arr[0]);
		if (carr[i] == 'B') printf("%d ", arr[1]);
		if (carr[i] == 'C') printf("%d ", arr[2]);
	}

	return 0;
}