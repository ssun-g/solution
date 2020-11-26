#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A[4001], B[4001], C[4001], D[4001];

int main() {
	int n;
	long long answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(A[i] + B[j]);
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long tmp = C[i] + D[j];
			long long low = lower_bound(v.begin(), v.end(), -tmp) - v.begin();
			long long upp = upper_bound(v.begin(), v.end(), -tmp) - v.begin();
			if (0 <= low && low < v.size() && -tmp == v[low])
				answer += (upp - low);
		}
	}
	cout << answer << '\n';

	return 0;
}