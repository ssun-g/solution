#include<bits/stdc++.h>
using namespace std;

int student[100];
int fireworks[2000001];

int main() {
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> student[i];
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= C; j++) {
			if (fireworks[j] != 0) continue;
			else if (j%student[i] == 0) {
				fireworks[j] = 1;
				answer++;
			}
		}
	}
	cout << answer << '\n';

	return 0;
}