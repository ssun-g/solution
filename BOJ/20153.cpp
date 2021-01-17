#include <bits/stdc++.h>
using namespace std;

int A[2222223][22];
int used[22], answer;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		// 1. 이진법으로 표현
		for (int j = 0; j < 22; j++) {
			if (num & (1 << j)) A[i][j] = 1;
		}

		// 2. 정수 x에 대해 2^x가 홀수 개 존재하면 2^x를 더하고
		//    짝수 개 존재하면 더하지 않는다. (XOR연산을 사용해 홀, 짝 판별)
		for (int j = 0; j < 22; j++) {
			if (A[i][j]) used[j] ^= 1;
		}
	}

	// 이진수 -> 십진수
	for (int i = 0; i < 22; i++) {
		if (used[i]) answer |= (1 << i);
	}

	for (int i = 1; i <= N; i++) {
		// 3. 최대 한 개 자연수 제거 해보면서 값을 구함
		for (int j = 0; j < 22; j++) {
			if (A[i][j]) used[j] ^= 1;
		}

		int cur = 0;
		for (int j = 0; j < 22; j++) {
			if (used[j]) cur |= (1 << j);
		}

		answer = max(answer, cur);

		for (int j = 0; j < 22; j++) {
			if (A[i][j]) used[j] ^= 1;
		}
	}
	cout << answer << answer << '\n';

	return 0;
}