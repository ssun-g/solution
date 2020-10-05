#include<cstdio>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	int pos = 0;
	printf("<");
	while (v.size() != 1) {
		pos += K - 1;
		if (pos >= v.size()) pos %= v.size();
		printf("%d, ", v[pos]);
		v.erase(v.begin() + pos);
	}
	printf("%d>", v.front());


	return 0;
}