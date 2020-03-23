#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<math.h>
using namespace std;

vector<pair<int, int>> mode;
vector<int> v;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	int tc;
	double sum = 0;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		sum += n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	mode.push_back(pair<int, int>(v[0], 1));

	for (int i = 1; i < v.size(); i++) {
		bool flag = false;
		for (int j = 0; j < mode.size(); j++) {
			if (v[i] == mode[j].first) {
				mode[j].second++;
				flag = true;
			}
		}
		if (!flag) mode.push_back(pair<int, int>(v[i], 1));
	}

	sort(mode.begin(), mode.end(), comp);

	int md;
	if (mode.size() == 1) md = mode[0].first;
	else md = (mode[0].second == mode[1].second) ? mode[1].first : mode[0].first;

	printf("%.0f\n%d\n%d\n%d", round(sum / tc), v[tc / 2], md, v[tc - 1] - v[0]);

	return 0;
}