#include<cstdio>
#include<algorithm>
using namespace std;

int weight();

int arr[5001], check[800000];
int w, n, Max, Min;

int main() {
	scanf_s("%d%d", &w, &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &arr[i]);

	sort(arr, arr + n + 1);

	Max = arr[n] + arr[n - 1] + arr[n - 2] + arr[n - 3];
	Min = arr[1] + arr[2] + arr[3] + arr[4];

	if (w > Max || w < Min) {
		printf("NO\n");
		return 0;
	}

	if (weight()) printf("YES\n");
	else printf("NO\n");

	return 0;
}

int weight() {
	int a, b, c, d;
	for (c = 3; c <= n - 1; c++) {
		for (d = c + 1; d <= n; d++)
			check[arr[c] + arr[d]] = 1;

		b = c - 1;
		for (a = 1; a <= b - 1; a++)
			if (check[w - (arr[a] + arr[b])]) return 1;
	}
	return 0;
}