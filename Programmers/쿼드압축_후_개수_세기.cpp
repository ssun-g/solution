#include <string>
#include <vector>

using namespace std;

int zero, one;
int Arr[1025][1025];

void dnc(int y, int x, int size) {
	int temp = Arr[y][x];
	bool isEqual = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (temp != Arr[i][j]) {
				isEqual = false;
				break;
			}
		}
	}

	if (isEqual && temp == 0) {
		zero++;
		return;
	}
	else if (isEqual && temp == 1) {
		one++;
		return;
	}

	dnc(y, x, size / 2);
	dnc(y, x + size / 2, size / 2);
	dnc(y + size / 2, x, size / 2);
	dnc(y + size / 2, x + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	int size = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			Arr[i][j] = arr[i][j];
		}
	}

	dnc(0, 0, size);
	answer.push_back(zero);
	answer.push_back(one);

	return answer;
}