#include<bits/stdc++.h>
using namespace std;

int arr[1001];

// 문제에서 주어진 수열을 만들어 준다.
void Init() {
	int idx = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			if (idx > 1000) return; // 최대 길이가 1000이므로 1000이 넘으면 함수를 종료
			arr[idx++] = i;
		}
	}
}

int main() {
	Init();
	int answer = 0;
	int A, B;
	cin >> A >> B;
	for (int i = A; i <= B; i++) { // 수열에서 A ~ B번째 숫자까지의 합
		answer += arr[i];
	}
	cout << answer << '\n';

	return 0;
}