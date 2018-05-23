#include<cstdio>
using namespace std;

int main() {
	int n, cute, cnt = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &cute);
		if (cute == 1) {
			cnt++;
		}
		else cnt--;
	}
	if (cnt > 0) {
		printf("Junhee is cute!\n");
	}
	else printf("Junhee is not cute!\n");

	return 0;
}