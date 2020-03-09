#include<cstdio>
#include<cmath>
using namespace std;

int prime[1001];
int comp[100];

void erat() {
	for (int i = 2; i*i <= 1000; i++) {
		if (!prime[i]) {
			for (int j = i*i; j <= 1000; j += i) {
				prime[j] = 1;
			}
		}
	}
}

int main() {
	erat();

	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &comp[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= 1000; j++) {
			if (!prime[j] && comp[i] <= j) {
				if (comp[i] < j) break;
				cnt++;
				break;
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}