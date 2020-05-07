#include<cstdio>
using namespace std;

int arr[10000];
int cnt, sum;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == m) {
				cnt++;
				break;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}
