#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int arr[9];

int main() {
	int MAX = -1;
	int flag = 1;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			if (flag == 1) arr[6]++;
			flag *= -1;
		}
		else arr[(int)(s[i] - '0')]++;
	}

	for (int i = 0; i < 9; i++) {
		MAX = (MAX < arr[i]) ? arr[i] : MAX;
	}
	printf("%d\n", MAX);

	return 0;
}