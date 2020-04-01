#include<cstdio>
using namespace std;

int main() {
	int E, S, M;
	int i = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (true) {
		if ((i - E) % 15 == 0 && (i - S) % 28 == 0 && (i - M) % 19 == 0) break;
		i++;
	}

	printf("%d\n", i);

	return 0;
}