#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land) {
	int answer = 0;
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int MAX = -1;
			for (int k = 0; k < 4; k++) {
				if (j == k) continue;
				MAX = (MAX < land[i - 1][k]) ? land[i - 1][k] : MAX;
			}
			land[i][j] += MAX;
		}
	}

	int idx = land.size() - 1;
	for (int i = 0; i < 4; i++) {
		answer = (answer < land[idx][i]) ? land[idx][i] : answer;
	}

	return answer;
}