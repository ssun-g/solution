#include<bits/stdc++.h>
using namespace std;

int N, K;
string order;

long long Sum(long long n) {
	// 자료형에 주의하자!!
	// int로 받을 시 계산 도중 32비트를 넘어갈 수 있다.
	return (n*(n + 1)) / 2;
}

long long findNum(int y, int x) {
	long long n = y + x + 1;
	long long end;

	if (n <= N) {
		end = Sum(n);
		if ((n - 1) % 2 == 0) return end - y;
		else return end - x;
	}
	else {
		end = Sum(N) + (Sum(N - 1) - Sum(N - (n - N) - 1));
		if ((n - 1) % 2 == 0) return end - ((N - 1) - x);
		else return end - ((N - 1) - y);
	}
}

long long jumpRabbit(int y, int x) {
	int curY = y;
	int curX = x;
	long long sum = 1;

	for (int i = 0; i < K; i++) {
		if (order[i] == 'U') curY--;
		else if (order[i] == 'D') curY++;
		else if (order[i] == 'L') curX--;
		else if (order[i] == 'R') curX++;

		sum += findNum(curY, curX);
	}

	return sum;
}

int main() {
	cin >> N >> K;
	cin >> order;

	cout << jumpRabbit(0, 0) << '\n';

	return 0;
}
