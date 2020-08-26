#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];

void Reset() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			arr[i][j] = 0;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		Reset();
		int n, m;
		vector<int> rows;
		vector<int> cols;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {
			int rowsum = 0;
			int colsum = 0;
			for (int j = 1; j <= n; j++) {
				rowsum += arr[i][j];
				colsum += arr[j][i];
			}
			rows.push_back(rowsum);
			cols.push_back(colsum);
		}

		for (int i = 0; i < m; i++) {
			int r1, r2, c1, c2, v;
			scanf("%d %d %d %d %d", &r1, &c1, &r2, &c2, &v);
			for (int j = r1; j <= r2; j++) {
				rows[j - 1] += v*(c2 - c1 + 1);
			}
			for (int j = c1; j <= c2; j++) {
				cols[j - 1] += v*(r2 - r1 + 1);
			}
		}

		for (int i = 0; i < rows.size(); i++) printf("%d ", rows[i]);
		printf("\n");
		for (int i = 0; i < rows.size(); i++) printf("%d ", cols[i]);
		printf("\n");
	}

	return 0;
}