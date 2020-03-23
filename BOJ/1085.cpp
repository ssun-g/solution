#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	int MIN;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	MIN = min(min(w - x, h - y), min(x - 0, y - 0));
	printf("%d\n", MIN);

	return 0;
}