#include<cstdio>
#include<queue>
using namespace std;

queue<int> q;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int f = q.front();
		q.pop();
		q.push(f);
	}
	printf("%d\n", q.front());

	return 0;
}