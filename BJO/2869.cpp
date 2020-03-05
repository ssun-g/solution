#include<cstdio>
using namespace std;

int main() {
	int a, b, v;
	int day;
	scanf("%d %d %d", &a, &b, &v);
	if ((v - b) % (a - b)) day = (v - b) / (a - b) + 1;
	else day = (v - b) / (a - b);

	printf("%d\n", day);

	return 0;
}