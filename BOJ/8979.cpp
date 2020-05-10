#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;

typedef struct Medal {
	int num;
	int gold;
	int silver;
	int bronze;
}Medal;

bool comp(Medal a, Medal b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	else if (a.silver != b.silver) return a.silver > b.silver;
	else if (a.bronze != b.bronze) return a.bronze > b.bronze;
	else return a.num == k;
}

int main() {
	vector<Medal> v;
	Medal M;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &M.num, &M.gold, &M.silver, &M.bronze);
		v.push_back(M);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].num == k) {
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}