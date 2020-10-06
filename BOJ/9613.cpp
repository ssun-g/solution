#include<cstdio>
using namespace std;

int arr[101];

void Reset() {
	for (int i = 0; i < 101; i++) {
		arr[i] = 0;
	}
}

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int num;
		long long sum = 0;
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < num; i++) {
			for (int j = i + 1; j < num; j++) {
				sum += GCD(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
		Reset();
	}

	return 0;
}