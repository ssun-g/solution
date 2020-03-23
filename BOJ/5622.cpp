#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int alpha[26];

int main() {
	int sum = 0;
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		int n = (int)(a[i] - 'A');
		if (n == 18 || n == 21 || n == 24 || n == 25) alpha[n] += n / 3 + 2;
		else alpha[n] += n / 3 + 3;
	}

	for (int i = 0; i < 26; i++) {
		sum += alpha[i];
	}
	printf("%d\n", sum);

	return 0;
}