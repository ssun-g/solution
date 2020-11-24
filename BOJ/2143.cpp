/*
첫 번째 배열의 부분 합을 모두 구한후 map에 저장한다.
그 후 두 번째 배열의 부분 합을 구하면서 (target - sum)값이 map에 존재하면
그 개수만큼 answer값을 증가시켜 준다.
(target-sum)값이 존재한다는 것은 첫번 째 배열의 부분 합과 두 번째 배열의 부분합을
더해 target값을 완성할 수 있다는 뜻.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int A[1001], B[1001];

int main() {
	unordered_map<int, int> ump;
	long long T;
	long long sum_A = 0, sum_B = 0;
	long long answer = 0;
	int n, m;
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum_A += A[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
		sum_B += B[i];
	}

	// partial sum of first array
	for (int i = 0; i < n; i++) {
		int sum = A[i];
		for (int j = i + 1; j < n; j++) {
			ump[sum]++;
			sum += A[j];
		}
		ump[sum]++;
	}

	// partial sum of second array
	// find the target
	for (int i = 0; i < m; i++) {
		int sum = B[i];
		for (int j = i + 1; j < m; j++) {
			answer += ump[T - sum];
			sum += B[j];
		}
		answer += ump[T - sum];
	}
	cout << answer << '\n';

	return 0;
}