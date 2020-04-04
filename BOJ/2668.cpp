#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int arr[101];
int check[101];

void Reset() {
	for (int i = 0; i < 101; i++) check[i] = 0;
}

void dfs(int start, int idx) {
	if (!check[idx]) {
		check[idx] = 1;
		dfs(start, arr[idx]);
	}
	else {
		if (start == idx) v.push_back(start);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		Reset();
		dfs(i, i);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}


	return 0;
}