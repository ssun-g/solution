/*

x, y�� ������ �ִ� 2^50�̹Ƿ� int�� �������� �� ��.

*/
#include <bits/stdc++.h>
using namespace std;

int d;
long long dx, dy;
long long dest_x, dest_y;
string piece;

void dnc(long long sx, long long sy, long long ex, long long ey, long long size, string quad) {  // ���������� �����ϸ鼭 �̵� ��ġ�� ã�´�.
	// �̵��� ��ġ�� �����ϸ� ���
	if (ex == dest_x && ey == dest_y && quad.length() == d) {
		cout << quad << '\n';
		exit(0);
	}

	// ���� ��и鿡 ������ ������ Ž������ �ʴ´�.
	if (!(sx < dest_x && dest_x <= ex && sy < dest_y && dest_y <= ey)) return;

	long long next = size / 2;
	dnc(sx + next, sy, ex, ey - next, next, quad + '1'); // 1��и�
	dnc(sx, sy, ex - next, ey - next, next, quad + '2'); // 2��и�
	dnc(sx, sy + next, ex - next, ey, next, quad + '3'); // 3��и�
	dnc(sx + next, sy + next, ex, ey, next, quad + '4'); // 4��и�
}

int main() {
	cin >> d >> piece;
	cin >> dx >> dy;

	long long init_x = pow(2, d);
	long long init_y = pow(2, d);
	long long size = pow(2, d - 1);
	for (int i = 0; i < piece.length(); i++) { // ���� ��ǥ ã��
		if (piece[i] == '1') init_y -= size;
		else if (piece[i] == '2') {
			init_x -= size;
			init_y -= size;
		}
		else if (piece[i] == '3') init_x -= size;

		size /= 2;
	}

	// �������� ��ǥ
	dest_x = init_x + dx;
	dest_y = init_y - dy;

	size = pow(2, d);
	dnc(0, 0, size, size, size, "");

	cout << -1 << '\n'; // ������ �� ������ -1

	return 0;
}