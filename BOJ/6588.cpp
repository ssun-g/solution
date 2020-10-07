#include<cstdio>
using namespace std;

bool isPrime[1000001];

void Eratos() {
	for (int i = 2; i <= 1000000; i++) isPrime[i] = true;
	for (int i = 2; i*i <= 1000000; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j <= 1000000; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	Eratos();
	while (true) {
		int n;
		bool wrong = true;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 3; i <= n; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				wrong = false;
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		if (wrong) printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}