#include<cstdio>
#include<algorithm>
using namespace std;

int fruit[1001];

int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &fruit[i]);
	}
	sort(fruit, fruit + n);

	for (int i = 0; i < n; i++) {
		if (fruit[i] <= l) l++;
	}

	printf("%d\n", l);

	return 0;
}