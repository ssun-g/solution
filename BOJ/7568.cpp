#include<cstdio>
#include<utility>
#include<vector>
using namespace std;

pair<int, int> p;
vector<pair<int, int>> v;

int Rank[50];

int main() {
	for (int i = 0; i < 50; i++) Rank[i] = 1;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}

	for (int i = 0; i < n; i++) {
		int curW = v[i].first;
		int curH = v[i].second;
		for (int j = 0; j < n; j++) {
			if (curW < v[j].first && curH < v[j].second) Rank[i]++;
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d ", Rank[i]);
	return 0;
}