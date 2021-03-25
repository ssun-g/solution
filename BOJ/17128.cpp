#include<bits/stdc++.h>
using namespace std;

int quality[200001];
int cow[200001];

int main() {
	ios_base::sync_with_stdio(false); // 두 줄을 쓰지 않으면 시간 초과가 발생한다.
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> cow[i];
	}

	for (int i = 0; i < 200001; i++) quality[i] = 1; // 원소들을 곱해줘야 하기 때문에 1로 초기화

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= i + 3; j++) { // quality[i]는 문제에서 주어진 S를 구하기 위한 A_i * A_i+1 * A_i+2 * A_i+3을 구현.
			if (j%N == 0) quality[i] *= cow[j]; // 0번째 index = N번째 index
			else quality[i] *= cow[j%N];
		}
		sum += quality[i];
	}

	for (int i = 0; i < Q; i++) {
		int idx;
		cin >> idx;
		for (int j = idx - 3; j <= idx; j++) {
			if (j%N == 0) { // 0번째 index = N번째 index
				quality[N] *= -1;
				sum += 2 * quality[N];
			}
			else if (j%N < 0) { // 음수이면 N+(j%N)번째 인덱스가 된다. ex) -1 -> N, -2 -> N-1
				quality[N + (j%N)] *= -1;
				sum += 2 * quality[N + (j%N)];
			}
			else {
				quality[j%N] *= -1;
				sum += 2 * quality[j%N];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
