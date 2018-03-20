#include<stdio.h>

int main() {
	int x, y, sum = 0;
	char month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char day[7][4] = { { "SUN" },{ "MON" },{ "TUE" },{ "WED" },{ "THU" },{ "FRI" },{ "SAT" } };
	scanf("%d%d", &x, &y);

	for (int i = 1; i < x; i++) {
		sum += month[i - 1];
	}
	sum += y;
	printf("%s", day[sum % 7]);
	return 0;
}
