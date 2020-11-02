#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	switch (N) {
	case 1:
		printf("1\n");
		break;
	case 2:
		if (M <= 6) printf("%d\n", (M + 1) / 2);
		else printf("4\n");
		break;
	default:
		if (M <= 4) printf("%d\n", M);
		else if (4 < M && M <= 6) printf("4\n");
		else printf("%d\n", M - 2);
		break;
	}

	return 0;
}