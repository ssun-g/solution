#include<bits/stdc++.h>
using namespace std;

int N;
long long dist[100001];
long long oil_price[100000];

long long solve() {
	long long oil = oil_price[0];
	long long ret = 0;
	for (int i = 1; i < N; i++) {
		ret += oil*dist[i];
		if (oil_price[i] < oil) oil = oil_price[i];
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> oil_price[i];
	}

	cout << solve() << '\n';

	return 0;
}