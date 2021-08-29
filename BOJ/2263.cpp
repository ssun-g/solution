#include <bits/stdc++.h>
using namespace std;

int n, idx;
int preorder[100001];
int inorder[100001];
int postorder[100001];
int node_idx[100001];

void dnc(int in_start, int in_end, int post_start, int post_end) {
	if (in_end < in_start || post_end < post_start) return;

	// 분할 정복을 위해 inorder에서 root를 기준으로 오른쪽, 왼쪽 subtree구간을 나눈다.
	int root = postorder[post_end]; // root node
	int root_idx = node_idx[root]; // root node index
	int l_len = root_idx - in_start; // 왼쪽 subtree
	int r_len = in_end - root_idx; // 오른쪽 subtree

	preorder[idx++] = root; // inorder 순회 하면서 root를 출력하면 preorder가 된다.

	dnc(in_start, root_idx - 1, post_start, post_end - r_len - 1); // 왼쪽 subtree 탐색
	dnc(root_idx + 1, in_end, post_start + l_len, post_end - 1); // 오른쪽 subtree 탐색
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> inorder[i];
	for (int i = 0; i < n; i++) cin >> postorder[i];
	for (int i = 0; i < n; i++) node_idx[inorder[i]] = i; // inorder에서 몇 번째로 등장하는 노드인지 저장

	dnc(0, n - 1, 0, n - 1);
	for (int i = 0; i < n; i++) cout << preorder[i] << ' ';

	return 0;
}