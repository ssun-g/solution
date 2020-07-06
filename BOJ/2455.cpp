#include<cstdio>
using namespace std;

int main() {
	int MAX = -1;
	int m, p, sum = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &m, &p);
		sum -= m;
		sum += p;
		MAX = (MAX < sum) ? sum : MAX;
	}
	printf("%d\n", MAX);

	return 0;
}