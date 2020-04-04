#include<cstdio>
#include<queue>
using namespace std;

int check[100001];

int main() {
	int n, k;
	int time = 0;
	scanf("%d %d", &n, &k);
	queue<int> q;
	q.push(n);


	while (true) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int tmp = q.front();
			q.pop();
			if (tmp == k) {
				printf("%d\n", time);
				return 0;
			}
			if (tmp > 0 && !check[tmp - 1]) {
				q.push(tmp - 1);
				check[tmp - 1] = 1;
			}
			if (tmp < 100000 && !check[tmp + 1]) {
				q.push(tmp + 1);
				check[tmp + 1] = 1;
			}
			if (tmp * 2 <= 100000 && !check[tmp * 2]) {
				q.push(tmp * 2);
				check[tmp * 2] = 1;
			}
		}
		time++;
	}

	return 0;
}