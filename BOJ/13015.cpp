#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	// 뚜껑
	for (int i = 0; i < n; i++) cout << '*';
	for (int i = 0; i < 3 * n - 3 - n; i++) cout << ' ';
	for (int i = 0; i < n; i++) cout << '*';
	cout << '\n';

	// 위
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < 3 * n - 3 - n - (i * 2); j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++) cout << ' ';
		cout << '*' << '\n';
	}

	// 가운데
	for (int i = 0; i < n - 1; i++) cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; j++) cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; j++) cout << ' ';
	cout << '*' << '\n';

	// 아래
	for (int i = n - 2; i > 0; i--) {
		for (int j = 0; j < i; j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < 3 * n - 3 - n - (i * 2); j++) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++) cout << ' ';
		cout << '*' << '\n';
	}

	// 바닥
	for (int i = 0; i < n; i++) cout << '*';
	for (int i = 0; i < 3 * n - 3 - n; i++) cout << ' ';
	for (int i = 0; i < n; i++) cout << '*';
	cout << '\n';

	return 0;
}