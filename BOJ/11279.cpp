#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(n);
	}

	return 0;
}