#include<cstdio>
#include<stack>
using namespace std;
stack<pair<int, int>> s[2];

int parent[100001] = { 0 };
int n;
int a, b;
int idx = 0;

int main(void) {
	scanf("%d", &n);
	parent[1] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (parent[a]) parent[b] = a;
		else if (parent[b]) parent[a] = b;
		else s[idx].push({ a, b });
	}
	while (!s[0].empty() || !s[1].empty()) {
		auto t = s[idx].top();
		a = t.first;
		b = t.second;
		s[idx].pop();

		if (parent[a]) {
			parent[b] = a;
		}
		else if (parent[b]) {
			parent[a] = b;
		}
		else {
			s[1 - idx].push({ a, b });
		}
		if (s[idx].empty()) {
			idx = 1 - idx;
		}
	}

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}