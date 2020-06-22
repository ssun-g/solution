#include<iostream>
#include<string>
using namespace std;

int main() {
	long long n;
	string res = "";
	cin >> n;
	while (n--) {
		res += 'a' + (char)(n % 26);
		n /= 26;
	}

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i];
	}
	return 0;
}