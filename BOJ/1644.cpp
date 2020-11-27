#include<iostream>
#include<vector>
using namespace std;

bool isPrime[4000001];
vector<int> primeNum;

void Eratos(int num) {
	for (int i = 0; i < 4000001; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i*i <= num; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j <= num; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= num; i++) {
		if (isPrime[i]) primeNum.push_back(i);
	}
}

int main() {
	int N;
	int answer = 0;
	cin >> N;

	Eratos(N);

	int left = 0, right = 0, sum = 0;
	while (left <= right) {
		if (sum >= N) sum -= primeNum[left++];
		else if (right == primeNum.size()) break;
		else sum += primeNum[right++];

		if (sum == N) answer++;
	}
	cout << answer << '\n';

	return 0;
}