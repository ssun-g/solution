#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[2500];
int check[100001];
vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	int n;
	double sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		check[arr[i]]++;
	}
	sort(arr, arr + n);

	for (int i = 1; i <= arr[n - 1]; i++) {
		if (check[i] != 0) v.push_back(make_pair(i, check[i]));
	}
	sort(v.begin(), v.end(), cmp);

	printf("%.1f\n", sum / n);
	if (n % 2 == 0) printf("%.1f\n", (double)(arr[n / 2] + arr[n / 2 - 1]) / 2);
	else printf("%.1f\n", (double)arr[n / 2] / 2);
	printf("%d", v[0].first);


	return 0;
}
