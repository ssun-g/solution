#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

stack <int> st;
queue <char> qu;

int main() {
	int n, m, max = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		if (max < m) {
			for (int i = max; i < m; i++) {
				st.push(i + 1);
				qu.push('+');
			}
		}
		if (st.top() == m && !st.empty()) {
			st.pop();
			qu.push('-');
			if (max < m)
				max = m;
		}
	}
	if (!st.empty()) {
		printf("NO\n");
		return 0;
	}
	while (!qu.empty()) {
		printf("%c\n", qu.front());
		qu.pop();
	}

	return 0;
}
