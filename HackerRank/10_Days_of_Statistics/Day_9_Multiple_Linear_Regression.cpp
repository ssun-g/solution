#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double x[101][11];
double y[101];
double xtx[11][11];
double xtx_1[11][11];
double xtxxt[11][101];
double b[11];
int row[11];

int main(void) {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		x[i][0] = 1;
		for (int j = 1; j <= m; j++)
			cin >> x[i][j];
		cin >> y[i];
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			xtx[i][j] = 0;
			for (int k = 0; k < n; k++)
				xtx[i][j] += x[k][i] * x[k][j];
		}
	}

	for (int i = 0; i <= m; i++) {
		row[i] = i;
		for (int j = 0; j <= m; j++)
			xtx_1[i][j] = 0;
		xtx_1[i][i] = 1;
	}

	for (int i = 0; i <= m; i++) {
		if ((i < m) && (fabs(xtx[row[i]][i]) <= 0.0000001))
			for (int j = i + 1; j <= m; j++)
				if (fabs(xtx[row[j]][i]) > 0.0000001) {
					int k = row[i];
					row[i] = row[j];
					row[j] = k;
					break;
				}
		double a = xtx[row[i]][i];
		for (int j = 0; j <= m; j++) {
			xtx[row[i]][j] /= a;
			xtx_1[row[i]][j] /= a;
		}
		xtx[row[i]][i] = 1;
		for (int j = i + 1; j <= m; j++) {
			a = xtx[row[j]][i];
			for (int k = 0; k <= m; k++) {
				xtx[row[j]][k] -= xtx[row[i]][k] * a;
				xtx_1[row[j]][k] -= xtx_1[row[i]][k] * a;
			}
		}
	}

	for (int i = m; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			double a = xtx[row[j]][i];
			for (int k = 0; k <= m; k++) {
				xtx[row[j]][k] -= xtx[row[i]][k] * a;
				xtx_1[row[j]][k] -= xtx_1[row[i]][k] * a;
			}
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			xtxxt[i][j] = 0;
			for (int k = 0; k <= m; k++)
				xtxxt[i][j] += xtx_1[row[i]][k] * x[j][k];
		}
	}

	for (int i = 0; i <= m; i++) {
		b[i] = 0;
		for (int k = 0; k < n; k++)
			b[i] += xtxxt[i][k] * y[k];
	}

	int q;
	cin >> q;
	cout << fixed << setprecision(3);
	for (int i = 0; i < q; i++) {
		double res = b[0];
		for (int j = 1; j <= m; j++) {
			double a;
			cin >> a;
			res += b[j] * a;
		}
		cout << res << endl;
	}
	return 0;
}
