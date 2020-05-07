#include<cstdio>
using namespace std;

int main() {
	int t, m;
	scanf("%d%d", &t, &m);
	if (m - 45 < 0) {
		m = 60 - ((m - 45)*-1);
		if (!t) t = 23;
		else t--;
	}
	else {
		m = m - 45;
	}
	printf("%d %d\n", t, m);

	return 0;
}