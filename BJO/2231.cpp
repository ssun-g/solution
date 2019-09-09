#include<cstdio>
using namespace std;

int main() {
	int n, i = 1, temp, sum = 0;
	scanf("%d", &n);

	while (1) {
		temp = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		sum += i;
		if (sum == n) {
			printf("%d", i);
			break;
		}
		sum = 0;
		i++;
		if (i > 1000000) {
			printf("0");
			break;
		}
	}

	return 0;
}