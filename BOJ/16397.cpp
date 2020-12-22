#include<bits/stdc++.h>
using namespace std;

int N, T, G;
int check[100000];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (check[cur] > T || cur == G) return;

		int A = cur + 1;
		if (A <= 99999 && check[A] == -1) {
			check[A] = check[cur] + 1;
			q.push(A);
		}

		int B = cur * 2;
		if (cur * 2 > 99999) continue;

		if (1 <= B && B <= 9 && check[B - 1] == -1) {
			B -= 1;
			check[B] = check[cur] + 1;
			q.push(B);
		}
		else if (10 <= B && B <= 99 && check[B - 10] == -1) {
			B -= 10;
			check[B] = check[cur] + 1;
			q.push(B);
		}
		else if (100 <= B && B <= 999 && check[B - 100] == -1) {
			B -= 100;
			check[B] = check[cur] + 1;
			q.push(B);
		}
		else if (1000 <= B && B <= 9999 && check[B - 1000] == -1) {
			B -= 1000;
			check[B] = check[cur] + 1;
			q.push(B);
		}
		else if (10000 <= B && B <= 99999 && check[B - 10000] == -1) {
			B -= 10000;
			check[B] = check[cur] + 1;
			q.push(B);
		}
	}
}

int main() {
	memset(check, -1, sizeof(check));
	cin >> N >> T >> G;

	bfs(N);

	if (check[G] > T || check[G] == -1) cout << "ANG" << '\n';
	else cout << check[G] << '\n';

	return 0;
}