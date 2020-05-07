#include <cstdio>
using namespace std;
int main() {
	int t, s, n, q, p, sum = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &s, &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d%d", &q, &p);
			sum += p * q;
		}
		printf("%d\n", sum + s);
		sum = 0;
	}
}