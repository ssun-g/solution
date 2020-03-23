#include<cstdio>
#include<algorithm>
using namespace std;

int l, c, check[16], c_cnt, v_cnt;
char letter[16], set[16];
void pass(int, int);

int main() {
	scanf("%d%d", &l, &c);

	for (int i = 0; i < c; i++) {
		scanf(" %c", &letter[i]);
	}
	sort(letter, letter + c);
	pass(0, 0);

	return 0;
}

void pass(int init, int cnt) {
	if (cnt == l) {
		if (v_cnt < 1 || c_cnt < 2) return;
		for (int i = 0; i < l; i++) {
			printf("%c", set[i]);
		}
		printf("\n");
		return;
	}
	for (int i = init; i < c; i++) {
		set[cnt] = letter[i];
		if (set[cnt] == 'a' || set[cnt] == 'i' || set[cnt] == 'u' || set[cnt] == 'e' || set[cnt] == 'o') {
			v_cnt++;
			pass(i + 1, cnt + 1);
			v_cnt--;
		}
		else {
			c_cnt++;
			pass(i + 1, cnt + 1);
			c_cnt--;
		}
	}
}