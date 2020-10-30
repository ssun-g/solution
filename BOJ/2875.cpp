#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int N, M, K;
	int cnt = 0;
	scanf("%d %d %d", &N, &M, &K);

	int team = min(N / 2, M);
	int modN = N - team * 2;
	int modM = M - team;

	if (modN != 0 || modM != 0)
		K = K - modN - modM;

	while (K > 0) {
		K -= 3;
		cnt++;
	}
	printf("%d\n", team - cnt);

	return 0;
}