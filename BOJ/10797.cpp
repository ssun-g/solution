#include<cstdio>
#include<algorithm>
using namespace std;

int arr[5];

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		if (n == arr[i]) cnt++;
	}
	printf("%d\n", cnt);


	return 0;
}