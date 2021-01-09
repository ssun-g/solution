#include<bits/stdc++.h>
using namespace std;

vector<vector<long long> > matrix;

vector<vector<long long> > matMul(const vector<vector<long long> >& a, const vector<vector<long long> >& b) {
	vector<vector<long long> > ret;
	ret.resize(a.size(), vector<long long>(a.size()));

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			for (int k = 0; k < a.size(); k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= 1000;
		}
	}

	return ret;
}

void matPow(vector<vector<long long> > a, long long b) {
	vector<vector<long long> > ret;
	ret.resize(a.size(), vector<long long>(a.size()));

	for (int i = 0; i < a.size(); i++) {
		ret[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) ret = matMul(ret, a);
		b /= 2;
		a = matMul(a, a);
	}

	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	long long N, B;
	cin >> N >> B;
	matrix.resize(N, vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}

	matPow(matrix, B);

	return 0;
}