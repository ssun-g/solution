#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, k, result = 0;
	int fruit[1000];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &fruit[i]);
	}

	sort(fruit, fruit + n);

	for (int i = 0; i < k; i++) {
		result += fruit[i];
	}
	printf("%d\n", result);

	return 0;
}
