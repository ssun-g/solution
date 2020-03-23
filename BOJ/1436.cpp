#include<cstdio>
using namespace std;

int main() {
	int n;
	int i = 666;
	int cnt = 0;
	scanf("%d", &n);
	while (i) {
		int tmp = i;
		while (tmp) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}
		if (cnt == n) {
			printf("%d\n", i);
			break;
		}
		i++;
	}

	return 0;
}