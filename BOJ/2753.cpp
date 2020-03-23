#include<cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if (n % 4 == 0) {
		if (n % 100 != 0) printf("1\n");
		else if (n % 400 == 0) printf("1\n");
		else printf("0\n");
	}
	else printf("0\n");

	return 0;
}