#include<cstdio>
using namespace std;

int main() {
	int tc;
	int h, w, n;
	int floor;
	int room;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d", &h, &w, &n);
		floor = (n%h == 0) ? h : n%h;
		room = (n%h == 0)? n / h :n / h + 1;
		printf("%d\n", floor * 100 + room);
	}

	return 0;
}