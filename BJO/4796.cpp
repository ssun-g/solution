#include<cstdio>

int main() {
	int l, p, v;
	int answer = 0, idx = 0;
	while (true) {
		scanf("%d %d %d", &l, &p, &v);
		if (!l && !p && !v) return 0;
		if (v%p > l) answer = (v / p*l) + l;
		else answer = (v / p * l) + v%p;

		printf("Case %d: %d\n", ++idx, answer);
	}

	return 0;
}