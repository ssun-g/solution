#include<cstdio>
#include<stack>
using namespace std;

int main() {
	stack<int> st[7];
	int n, p;
	int answer = 0;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		int note, fret;
		scanf("%d %d", &note, &fret);

		if (st[note].empty() || st[note].top() < fret) {
			st[note].push(fret);
			answer++;
		}
		else if (st[note].top() >= fret) {
			while (!st[note].empty() && st[note].top() > fret) {
				st[note].pop();
				answer++;
			}

			if (st[note].empty() || st[note].top() != fret) {
				st[note].push(fret);
				answer++;
			}
		}
	}
	printf("%d\n", answer);

	return 0;
}