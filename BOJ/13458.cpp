#include<cstdio>
#define SIZE 1000000
using namespace std;

int room[SIZE];

int main() {
	int n, b, c;
	long long cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &room[i]);
	}
	scanf("%d %d", &b, &c);

	for (int i = 0; i < n; i++) {
		room[i] -= b;
		cnt++;
		if (room[i] > 0) {
			if (room[i] % c == 0) cnt += (room[i] / c);
			else cnt += (room[i] / c) + 1;
		}
	}
	printf("%lld\n", cnt);


	return 0;
}