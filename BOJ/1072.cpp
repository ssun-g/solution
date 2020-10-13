#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	long long X, Y;
	long long answer = 1000000001;
	scanf("%lld %lld", &X, &Y);

	long long left = 0;
	long long right = 1000000000;
	long long mid;
	int Z = (100 * Y) / X;
	while (left <= right) {
		mid = (left + right) / 2;
		int win = ((100 * (Y + mid)) / (X + mid));
		if (Z < win) {
			right = mid - 1;
			answer = min(answer, mid);
		}
		else if (Z == win) left = mid + 1;
	}
	if (answer == 1000000001) printf("-1\n");
	else printf("%lld\n", answer);

	return 0;
}