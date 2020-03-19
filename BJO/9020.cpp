#include<cstdio>
using namespace std;

int arr[10001];
int gold[10001];

void eratos() {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i*i <= 10001; i++) {
		if (!arr[i]) {
			for (int j = i*i; j <= 10001; j += i) {
				arr[j] = 1;
			}
		}
	}
}

int main() {
	eratos();
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		for (int j = n / 2; j > 0; j--) {
			if (!arr[j] && !arr[n - j]) {
				printf("%d %d\n", j, n - j);
				break;
			}
		}
	}
	return 0;
}