#include <bits/stdc++.h>

using namespace std;

int dx[6] = { 1, 2, 1, 0, 1, 2 };
int dy[6] = { 0, 0, 1, 2, 2, 2 };

int hourglass(vector<vector<int>> arr, int y, int x) {
	int sum = arr[y][x];
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		sum += arr[ny][nx];
	}

	return sum;
}


int main()
{
	int MAX = -64;
	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i < 4 && j < 4) MAX = max(MAX, hourglass(arr, i, j));
		}
	}
	printf("%d\n", MAX);

	return 0;
}
