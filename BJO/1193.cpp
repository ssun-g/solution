#include<cstdio>
using namespace std;

int main() {
	int x, num;
	int n = 1;
	scanf("%d", &x);
	while (true) {
		num = (n*n - n + 2) / 2;
		if (num >= x) {
			if (num > x) n--;
			break;
		}
		n++;
	}
	num = (n*n - n + 2) / 2;
	if (num == x) {
		if (n % 2 == 0) printf("%d/%d\n", 1, n);
		else printf("%d/%d", n, 1);
	}
	else {
		if (n % 2 == 0) printf("%d/%d\n", 1 + (x - num), n - (x - num));
		else printf("%d/%d", n - (x - num), 1 + (x - num));
	}



	return 0;
}