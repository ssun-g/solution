#include<cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int d, n, s, p;
		int par, ser;
		scanf("%d %d %d %d", &d, &n, &s, &p);
		par = n*p + d;
		ser = s*n;
		if (par > ser) printf("do not parallelize\n");
		else if (par < ser) printf("parallelize\n");
		else printf("does not matter\n");
	}

	return 0;
}