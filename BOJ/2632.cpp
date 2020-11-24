#include<iostream>
#include<unordered_map>
using namespace std;

int A[1001], B[1001];

unordered_map<int, int> partialSum(int arr[], int size) {
	unordered_map<int, int> ump;
	int sum = 0;
	ump[sum]++;
	for (int i = 0; i < size; i++) {
		sum = arr[i];
		for (int j = i + 1; j < size; j++) {
			ump[sum]++;
			sum += arr[j];
		}
		ump[sum]++;
	}

	sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	for (int i = size - 2; i >= 1; i--) {
		int tmp = arr[i];
		for (int j = i - 1; j >= 1; j--) {
			ump[sum - tmp]++;
			tmp += arr[j];
		}
		ump[sum - tmp]++;
	}

	return ump;
}

int main() {
	unordered_map<int, int> psum;
	int target, m, n;
	long long answer = 0;
	cin >> target >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	psum = partialSum(A, m);

	// 두 번째 피자의 부분 합 [0 ~ n) 구간 부분 합
	int sum = 0;
	answer += psum[target - sum];
	for (int i = 0; i < n; i++) {
		sum = B[i];
		for (int j = i + 1; j < n; j++) {
			answer += psum[target - sum];
			sum += B[j];
		}
		answer += psum[target - sum];
	}

	/*
	피자는 원형이기 때문에 뒤의 인덱스부터 앞 인덱스로 이어지는
	구간에서의 부분합도 구해주어야 한다. 전체 합에서 가운데 부분만 빼는 방식으로 구함
	*/
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += B[i];
	}

	for (int i = n - 2; i >= 1; i--) {
		int tmp = B[i];
		for (int j = i - 1; j >= 1; j--) {
			answer += psum[target - (sum - tmp)];
			tmp += B[j];
		}
		answer += psum[target - (sum - tmp)];
	}
	cout << answer << '\n';

	return 0;
}