#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int m, len;
	cin >> n >> m;
	len = stoi(n);

	if (n.length()*len > m) {
		int size = m / n.length();
		for (int i = 0; i < size; i++)
			cout << n;

		if (m%n.length() != 0) {
			for (int i = 0; i < m%n.length(); i++)
				cout << n[i];
		}

	}
	else {
		for (int i = 0; i < len; i++)
			cout << n;
	}

	return 0;
}