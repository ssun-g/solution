#include<bits/stdc++.h>
using namespace std;

// x원을 연 이율 rates%로 month동안 매달 payment만큼 지불했을 때의 잔금
double balance(double x, int month, double rates, double payment) {
	double money = x;
	for (int i = 0; i < month; i++) {
		money *= 1 + (rates / 12) / 100;
		money -= payment;
	}

	return money;
}

void solve(double x, int month, double rates) {
	double left = 0, right = x * (1 + (rates / 12) / 100);
	for (int i = 0; i < 100; i++) {
		double mid = (left + right) / 2;
		if (balance(x, month, rates, mid) > 0)
			left = mid;
		else
			right = mid;
	}
	cout << fixed << setprecision(8);
	cout << left << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int M;
		double N, P;
		cin >> N >> M >> P;
		solve(N, M, P);
	}


	return 0;
}