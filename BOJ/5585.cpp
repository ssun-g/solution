#include<cstdio>
using namespace std;

int coin[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	int pay;
	int result = 0;
	scanf("%d", &pay);

	int ch = 1000 - pay;
	for (int i = 0; i < 6; i++) {
		if (ch < coin[i]) continue;
		result += ch / coin[i];
		ch %= coin[i];
	}
	printf("%d\n", result);

	return 0;
}