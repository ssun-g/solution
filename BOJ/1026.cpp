#include<cstdio>
#include<algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int num[50] = { 0, };
	int num2[50] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num2[i]);
	}
	sort(num, num + n, comp);
	sort(num2, num2 + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] * num2[i];
	}
	printf("%d\n", sum);

	return 0;
}