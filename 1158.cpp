#include<cstdio>
#include<queue>
using namespace std;
queue <int> qu;


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		qu.push(i);
	}

	printf("<");
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			qu.push(qu.front());
			qu.pop();
		}
		printf("%d, ", qu.front());
		qu.pop();
	}
	printf("%d", qu.front());
	printf(">");

	return 0;
}