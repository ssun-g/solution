#include<cstdio>
using namespace std;

int check[42];

int main() {
	int n;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		check[n % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (check[i]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}