#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int MIN = 51;
	string a, b;
	cin >> a >> b;
	int idx = 0;
	while (true) {
		if (b.length() - a.length() < idx) break;
		int cnt = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i + idx]) cnt++;
		}
		idx++;
		MIN = (cnt < MIN) ? cnt : MIN;
	}
	printf("%d\n", MIN);

	return 0;
}