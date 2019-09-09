#include<cstdio>
using namespace std;

int n, cnt, p, k = 2;
char temp[1023], visited[1023], ans[1023][1023];
bool ok = false;
void go(int, int);

int main() {
	scanf("%d", &n);
	if (n < 10) printf("%d\n", n);
	else if (n >= 1023) printf("-1\n");
	else {
		cnt = 9;
		for (int i = 2; i <= 10; i++) {
			go(0, 0);
			k++;
		}
	}
	return 0;
}

void go(int index, int depth) {
	if (ok) return;
	if (index > k) return;
	if (depth == k) {
		bool check = false;
		for (int i = 0; i < depth - 1; i++) {
			if (temp[i] < temp[i + 1]) check = true;
			else continue;
		}
		if (check) return;
		else {
			for (int i = 0; i < depth; i++) {
				ans[p][i] = temp[i];
			}
			p++;
			cnt++;
			if (cnt == n) {
				printf("%s\n", ans[p - 1]);
				ok = true;
				return;
			}
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp[index] = i + '0';
			go(index + 1, depth + 1);
			visited[i] = false;
			temp[index] = ' ';
		}
	}
}