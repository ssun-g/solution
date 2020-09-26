#include<cstdio>
#include<map>
using namespace std;

map<long long, int> mp;

bool comp(pair<long long, int> a, pair<long long, int> b) {
	if (a.second == b.second) a.first < b.first;
	return a.second > b.second;
}

int main() {
	long long answer = 0;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long long num;
		scanf("%lld", &num);
		mp[num]++;
	}

	int cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (cnt < it->second) {
			answer = it->first;
			cnt = it->second;
		}
	}
	printf("%lld", answer);

	return 0;
}