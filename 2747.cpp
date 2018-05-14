#include<cstdio>
using namespace std;

int main() {
	int num, fibo[46];
	fibo[0] = 0;
	fibo[1] = 1;

	scanf("%d", &num);

	for (int i = 2; i <= num; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	printf("%d\n", fibo[num]);

	return 0;
}
