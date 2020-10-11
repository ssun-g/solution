#include<iostream>
using namespace std;

char tree[27][2];

void preOrder(char cur) {
	if (cur == '.') return;
	cout << cur;
	preOrder(tree[cur - 'A'][0]);
	preOrder(tree[cur - 'A'][1]);
}

void inOrder(char cur) {
	if (cur == '.') return;
	inOrder(tree[cur - 'A'][0]);
	cout << cur;
	inOrder(tree[cur - 'A'][1]);
}

void postOrder(char cur) {
	if (cur == '.') return;
	postOrder(tree[cur - 'A'][0]);
	postOrder(tree[cur - 'A'][1]);
	cout << cur;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char cur, lc, rc;
		cin >> cur >> lc >> rc;
		tree[cur - 'A'][0] = lc;
		tree[cur - 'A'][1] = rc;
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';

	return 0;
}