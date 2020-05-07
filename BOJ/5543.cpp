#include<cstdio>
#include<algorithm>
using namespace std;

int bur[3];
int drink[2];

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &bur[i]);
	}

	for (int i = 0; i < 2; i++) {
		scanf("%d", &drink[i]);
	}
	sort(bur, bur + 3);
	sort(drink, drink + 2);

	printf("%d", bur[0] + drink[0] - 50);

	return 0;
}