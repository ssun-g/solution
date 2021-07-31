#include<bits/stdc++.h>
using namespace std;

class Tree {
public:
	int lc, rc;

	Tree(int lc, int rc) {
		this->lc = lc;
		this->rc = rc;
	}
};

int cols; // node�� ���� ��ġ
int check_root[10001];
vector<int> stats[10001]; // node�� level�� ���� ��ġ ����
vector<Tree> tree[10001];

void inOrder(int cur_node, int depth) {
	int lc = tree[cur_node][0].lc;
	int rc = tree[cur_node][0].rc;

	if (lc != -1) inOrder(lc, depth + 1);

	stats[depth].push_back(cols); // ���� ��ȸ�ϸ鼭 level�� node�� ��ġ�� �����Ѵ�.
	cols++;

	if (rc != -1) inOrder(rc, depth + 1);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int node, lc, rc;
		cin >> node >> lc >> rc;
		tree[node].push_back(Tree(lc, rc));
		check_root[lc] = 1;
		check_root[rc] = 1;
	}

	int root;
	for (int i = 1; i <= N; i++) { // �ڽĳ��� ������ ���� ������ ��Ʈnode�� �ƴϴ�.
		if (!check_root[i]) {
			root = i;
			break;
		}
	}

	inOrder(root, 1);

	int level = 1, max_len = 1;
	for (int i = 2; i <= N; i++) { // level 1�� ��Ʈ����̹Ƿ� �Ѿ��.
		if (stats[i].empty()) break;

		int width = stats[i][stats[i].size() - 1] - stats[i][0] + 1;
		if (max_len < width) {
			max_len = width;
			level = i;
		}
	}
	cout << level << ' ' << max_len << '\n';

	return 0;
}