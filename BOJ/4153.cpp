#include<cstdio>
#include<algorithm>
using namespace std;

int arr[3];

int main() {
	while (true) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (!arr[0] && !arr[1] && !arr[2]) break;
		sort(arr, arr + 3);
		if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}