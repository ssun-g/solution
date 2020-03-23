#include<cstdio>
#include<algorithm>
using namespace std;

int r, g, b, x, y, z;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &r, &g, &b);
		r = r + min(y, z);
		g = g + min(x, z);
		b = b + min(x, y);
		x = r;
		y = g;
		z = b;
	}
	printf("%d", x > y ? min(y, z) : min(x, z));

	return 0;
}
