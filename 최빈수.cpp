#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
pair <int, int> p;

int student[101];

void reset(int arr[]) {
	for (int i = 0; i <= 100; i++) {
		arr[i] = 0;
	}
}

int freq(int arr[]) {
	p.first = -1;
	for (int i = 0; i <= 100; i++) {
		if (p.first <= arr[i]) {
			p.first = arr[i];
			p.second = i;
		}
	}
	return p.second;
}

int main() {
	int tc, num, score;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> num;
		reset(student);
		for (int j = 0; j < 1000; j++) {
			cin >> score;
			student[score]++;
		}
		cout << '#' << num << ' ' << freq(student) << endl;
	}

	return 0;
}
