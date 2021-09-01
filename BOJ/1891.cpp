/*

x, y의 범위가 최대 2^50이므로 int로 선언하지 말 것.

*/
#include <bits/stdc++.h>
using namespace std;

int d;
long long dx, dy;
long long dest_x, dest_y;
string piece;

void dnc(long long sx, long long sy, long long ex, long long ey, long long size, string quad) {  // 분할정복을 진행하면서 이동 위치를 찾는다.
	// 이동한 위치에 도착하면 출력
	if (ex == dest_x && ey == dest_y && quad.length() == d) {
		cout << quad << '\n';
		exit(0);
	}

	// 현재 사분면에 속하지 않으면 탐색하지 않는다.
	if (!(sx < dest_x && dest_x <= ex && sy < dest_y && dest_y <= ey)) return;

	long long next = size / 2;
	dnc(sx + next, sy, ex, ey - next, next, quad + '1'); // 1사분면
	dnc(sx, sy, ex - next, ey - next, next, quad + '2'); // 2사분면
	dnc(sx, sy + next, ex - next, ey, next, quad + '3'); // 3사분면
	dnc(sx + next, sy + next, ex, ey, next, quad + '4'); // 4사분면
}

int main() {
	cin >> d >> piece;
	cin >> dx >> dy;

	long long init_x = pow(2, d);
	long long init_y = pow(2, d);
	long long size = pow(2, d - 1);
	for (int i = 0; i < piece.length(); i++) { // 시작 좌표 찾기
		if (piece[i] == '1') init_y -= size;
		else if (piece[i] == '2') {
			init_x -= size;
			init_y -= size;
		}
		else if (piece[i] == '3') init_x -= size;

		size /= 2;
	}

	// 목적지의 좌표
	dest_x = init_x + dx;
	dest_y = init_y - dy;

	size = pow(2, d);
	dnc(0, 0, size, size, size, "");

	cout << -1 << '\n'; // 도달할 수 없으면 -1

	return 0;
}