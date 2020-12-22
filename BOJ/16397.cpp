#include<bits/stdc++.h>
using namespace std;

int N, T, G;
int check[100000];

int digitCnt(int num) {
	int ret = 0;
	while (num) {
		num /= 10;
		ret++;
	}

	return pow(10, ret - 1);
}

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

		int digit = digitCnt(B);
		B -= digit;

		if (check[B] == -1) {
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