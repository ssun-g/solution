#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];

// a, b, c의 범위가 -50 ~ 50 이기 때문에 배열을 사용하기 위해
// 각각 +50 해주어 범위를 0 ~ 100으로 설정
int solve(int a, int b, int c) {
	if (a <= 50 || b <= 50 || c <= 50)return 1;
	if (a > 70 || b > 70 || c > 70) return solve(70, 70, 70);

	int &ret = dp[a][b][c];
	if (ret != 0) return ret;

	if (a < b && b < c) ret = (solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c));
	else ret = (solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1));

	return ret;
}

int main() {
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		else {
			cout << "w(";
			cout << a << ", ";
			cout << b << ", ";
			cout << c << ") = ";
			cout << solve(a + 50, b + 50, c + 50) << '\n';;
		}
	}

	return 0;
}