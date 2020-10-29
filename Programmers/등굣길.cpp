#include <string>
#include <vector>

using namespace std;

int dp[101][101];
bool pud[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	for (int i = 0; i < puddles.size(); i++) {
		pud[puddles[i][1]][puddles[i][0]] = true;
	}

	for (int i = 1; i <= m; i++) {
		if (pud[1][i] == true) {
			dp[1][i] = 0;
			break;
		}
		else dp[1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (pud[i][1] == true) {
			dp[i][1] = 0;
			break;
		}
		else dp[i][1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (pud[i][j]) dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}
	answer = dp[n][m];

	return answer;
}