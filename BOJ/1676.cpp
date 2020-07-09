#include<cstdio>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	printf("%d\n", cnt);

	return 0;
}