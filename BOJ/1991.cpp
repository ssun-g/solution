#include <cstdio>
#include <vector>
using namespace std;
vector<pair<char, char>> arr[26];

void preorder(int);
void inorder(int);
void postorder(int);

int main() {
	int n;
	char node, left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &node, &left, &right);
		arr[node - 'A'].push_back(make_pair(left, right));
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");

	return 0;
}

void preorder(int root) {
	char leftchild = arr[root - 'A'].front().first;
	char rightchild = arr[root - 'A'].front().second;

	printf("%c", root);
	if (leftchild != '.') preorder(leftchild);
	if (rightchild != '.') preorder(rightchild);
}

void inorder(int root) {
	char leftchild = arr[root - 'A'].front().first;
	char rightchild = arr[root - 'A'].front().second;

	if (leftchild != '.') inorder(leftchild);
	printf("%c", root);
	if (rightchild != '.') inorder(rightchild);
}

void postorder(int root) {
	char leftchild = arr[root - 'A'].front().first;
	char rightchild = arr[root - 'A'].front().second;

	if (leftchild != '.') postorder(leftchild);
	if (rightchild != '.') postorder(rightchild);
	printf("%c", root);
}