#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n, m, Min = 10001, sum = 0, po;
	scanf("%d%d", &n, &m);
	for (int j = 1; j <= 100; j++) {
		po = pow(j, 2);
		if (n <= po && po <= m) {
			Min = min(po, Min);
			sum += po;
		}
	}
	if (Min == 10001) {
		printf("-1");
		return 0;
	}
	printf("%d\n%d", sum, Min);

	return 0;
}