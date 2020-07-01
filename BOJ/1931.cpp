#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Conf {
	int start;
	int endd;
}Conf;

bool comp(Conf a, Conf b) {
	if (a.endd == b.endd) return a.start < b.start;
	return a.endd < b.endd;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<Conf> c(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i].start, &c[i].endd);
	}
	sort(c.begin(), c.end(), comp);

	int cnt = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp <= c[i].start) {
			cnt++;
			tmp = c[i].endd;
		}
	}
	printf("%d\n", cnt);


	return 0;
}