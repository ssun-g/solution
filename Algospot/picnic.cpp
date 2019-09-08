#include<cstdio>
#include<utility>
using namespace std;
pair<int, int> p;

void Clear();
int Picnic();

int Friend[10][10];
int check[10];
int n, m, cnt;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &n, &m);
		Clear();
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &p.first, &p.second);
			Friend[p.first][p.second] = 1;
			Friend[p.second][p.first] = 1;
		}
		cnt = 0;
		printf("%d\n", Picnic());
	}

	return 0;
}

int Picnic() {
	int Min = -1;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			Min = i;
			break;
		}
	}
	if (Min == -1) return ++cnt;

	for (int i = Min + 1; i < n; i++) {
		if (!check[i] && !check[Min] && Friend[i][Min]) {
			check[Min] = 1;
			check[i] = 1;
			Picnic();
			check[Min] = 0;
			check[i] = 0;
		}
	}
	return cnt;
}

void Clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Friend[i][j] = 0;
		}
	}
}
