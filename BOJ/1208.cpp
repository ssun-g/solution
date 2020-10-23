#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int N, S;
int arr[1000001];
int check[1000001];
long long answer;
unordered_map<int, int> ump;

void dfsLeft(int init, int sum) {
	ump[sum]++;
	for (int i = init; i < N / 2; i++) {
		if (!check[i]) {
			check[i] = 1;
			dfsLeft(i + 1, sum + arr[i]);
			check[i] = 0;
		}
	}
}

void dfsRight(int init, int sum) {
	if (ump[S - sum] != 0) answer += ump[S - sum];
	for (int i = init; i < N; i++) {
		if (!check[i]) {
			check[i] = 1;
			dfsRight(i + 1, sum + arr[i]);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	dfsLeft(0, 0);
	dfsRight(N / 2, 0);

	if (S == 0) answer--;
	printf("%lld\n", answer);

	return 0;
}