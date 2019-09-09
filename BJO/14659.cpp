#include<cstdio>
#include<algorithm>
using namespace std;

int n, Max, han[30000], cnt;
void go(int);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &han[i]);
	}
	go(0);
	printf("%d", Max);

	return 0;
}

void go(int num) {
	if (num + Max + 1 >= n)	return;
	for (int i = num + 1; i < n; i++) {
		if (han[num] > han[i]) {
			cnt++;
		}
		else {
			Max = max(Max, cnt);
			cnt = 0;
			go(num + 1);
			break;
		}
		Max = max(Max, cnt);
	}
}