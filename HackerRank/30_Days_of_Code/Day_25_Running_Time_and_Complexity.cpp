#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return 1;
	}

	return 0;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		if (n == 1 || isPrime(n)) cout << "Not prime" << '\n';
		else cout << "Prime" << '\n';
	}

	return 0;
}
