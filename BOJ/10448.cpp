#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int tnum[45];
int check[45];
vector<int> v;

void TriNumInit() {
	for (int i = 1; i < 45; i++) {
		tnum[i] = (i*(i + 1)) / 2;
	}
}

void Eureka(int sum, int cnt) {
	if (sum > 1000) return;
	if (cnt == 3 && sum <= 1000) {
		v.push_back(sum);
		return;
	}

	for (int i = 1; i < 45; i++) {
		Eureka(sum + tnum[i], cnt + 1);
	}
}

int main() {
	TriNumInit();
	Eureka(0, 0);
	sort(v.begin(), v.end());

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < v.size(); i++) {
			if (n < v[i]) {
				printf("0\n");
				break;
			}
			else if (n == v[i]) {
				printf("1\n");
				break;
			}
		}
	}

	return 0;
}