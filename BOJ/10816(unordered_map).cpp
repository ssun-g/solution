#include<cstdio>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map<int, int> mp;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int card;
		scanf("%d", &card);
		mp[card]++;
	}

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int mcard;
		scanf("%d", &mcard);
		printf("%d ", mp[mcard]);
	}

	return 0;
}