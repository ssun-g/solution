#include<iostream>
#include<vector>
using namespace std;

int m;
int arr[25];

void ChangeScale(int arr[], int from, int to) {
	vector<int> v;
	int tmp = 0;
	int result = 0;
	int digit = 1;
	for (int i = m - 1; i >= 0; i--) {
		tmp += digit*arr[i];
		digit *= from;
	}

	digit = 1;
	while (tmp) {
		v.push_back(tmp % to);
		tmp = tmp / to;;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}
}

int main() {
	int A, B;
	cin >> A >> B;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	ChangeScale(arr, A, B);

	return 0;
}