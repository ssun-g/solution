#include<bits/stdc++.h>
using namespace std;

int helmet[1000];
int jacket[1000];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> helmet[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> jacket[i];
	}
	sort(helmet, helmet + N);
	sort(jacket, jacket + M);

	cout << helmet[N - 1] + jacket[M - 1] << '\n';

	return 0;
}