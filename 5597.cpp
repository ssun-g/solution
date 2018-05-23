#include<cstdio>
#include<algorithm>
using namespace std;

int check[30];
int cmp[2];

int main() {
	int n, cnt = 28, index = 0;
	while (cnt--) {
		scanf("%d", &n);
		check[n - 1] = 1;
	}

	for (int i = 0; i < 30; i++) {
		if (!check[i]) {
			cmp[index++] = i + 1;
		}
	}
	printf("%d\n%d", min(cmp[0], cmp[1]), max(cmp[0], cmp[1]));

	return 0;
}