#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int tc;
	int x1, y1, x2, y2, r1, r2;
	int dis;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if (r1 > r2) swap(r1, r2);
		dis = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		if (dis < (r1 + r2)*(r1 + r2) && (r2 - r1)*(r2 - r1) < dis) printf("2\n");
		else if (dis == (r1 + r2)*(r1 + r2)) printf("1\n");
		else if (dis == (r2 - r1)*(r2 - r1) && dis != 0) printf("1\n");
		else if (dis < (r2 - r1)*(r2 - r1)) printf("0\n");
		else if ((r1 + r2)*(r1 + r2) < dis) printf("0\n");
		else if (dis == 0 && r1 == r2) printf("-1\n");
		else if (dis == 0 && r1 != r2) printf("0\n");
	}

	return 0;
}