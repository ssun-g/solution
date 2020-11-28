#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	int answer = 987654321;
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0, right = 0, sum = 0, length = 0;
	while (left <= right) {
		if (sum >= S) {
			sum -= arr[left++];
			length--;
		}
		else if (right == N) break;
		else {
			sum += arr[right++];
			length++;
		}

		if (sum >= S) answer = min(answer, length);
	}
	if (answer == 987654321) cout << 0 << '\n';
	else cout << answer << '\n';

	return 0;
}