#include<cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		long long x, y, dis, result, i = 1;
		scanf("%lld %lld", &x, &y);
		dis = y - x;
		while (i++) {
			if (i*i > dis) break;
		}

		if ((i - 1)*(i - 1) == dis) result = 2 * i - 3;
		else if ((i*i + ((i - 1)*(i - 1))) / 2 >= dis) result = 2 * (i - 1);
		else result = 2 * (i - 1) + 1;
		printf("%d\n", result);
	}

	return 0;
}