#include<cstdio>
#include<cstring>
using namespace std;

int main(void) {
	char arr[16], cmp[16] = "1 2 3 4 5 6 7 8", cmp2[16] = "8 7 6 5 4 3 2 1";
	int i;
	scanf("%[^\n]s", arr);

	if (!strcmp(arr, cmp)) {
		printf("ascending\n");
	}
	else if (!strcmp(arr, cmp2)) {
		printf("descending\n");
	}
	else printf("mixed\n");

	return 0;
}