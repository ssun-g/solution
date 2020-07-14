#include<cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b;
		int result = 1;
		scanf("%d %d", &a, &b);
		for (int i = 0; i < b; i++) {
			result *= a;
			while (result >= 10) {
				result %= 10;
			}
		}
		if (result == 0) result = 10;
		printf("%d\n", result);
	}

	return 0;
}