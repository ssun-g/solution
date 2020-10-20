#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];

vector<int> solution(int n) {
	int idxx = 0, idxy = 0, fillNum = 1;
	int state = 0; // 0: down, 1: right, 2:up
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		if (state == 0) {
			for (int j = i; j < n; j++) {
				arr[idxy++][idxx] = fillNum++;
			}
			idxy--;
			idxx++;
			state = 1;
		}
		else if (state == 1) {
			for (int j = i; j < n; j++) {
				arr[idxy][idxx++] = fillNum++;
			}
			idxx -= 2;
			idxy--;
			state = 2;
		}
		else {
			for (int j = i; j < n; j++) {
				arr[idxy--][idxx--] = fillNum++;
			}
			idxx++;
			idxy += 2;
			state = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(arr[i][j]);
		}
	}

	return answer;
}