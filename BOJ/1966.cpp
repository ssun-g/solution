#include<cstdio>
using namespace std;

int arr[100];

void Reset() {
	for (int i = 0; i < 100; i++) {
		arr[i] = 0;
	}
}

void max_cmp(int arr[], int size, int &MAX) {
	for (int i = 0; i < size; i++) {
		MAX = (MAX < arr[i]) ? arr[i] : MAX;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		int cnt = 0;
		int MAX = -1;
		Reset();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			MAX = (MAX < arr[i]) ? arr[i] : MAX;
		}

		bool flag = false;
		while (true) {
			if (flag) break;
			for (int i = 0; i < n; i++) {
				if (MAX == arr[i]) {
					MAX = -1;
					arr[i] = -1;
					cnt++;
					max_cmp(arr, n, MAX);
					if (i == m) {
						flag = true;
						printf("%d\n", cnt);
						break;
					}
				}
			}
		}
	}

	return 0;
}