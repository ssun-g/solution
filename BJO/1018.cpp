#define MIN(x, y) ((x < y)? x : y)

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> chess;
string cmpW[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string cmpB[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int changeW(int x, int y) {
	int cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (chess[i][j] != cmpW[i - y][j - x]) cnt++;
		}
	}

	return cnt;
}

int changeB(int x, int y) {
	int cnt = 0; 
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (chess[i][j] != cmpB[i - y][j - x]) cnt++;
		}
	}
	
	return cnt;
}

int main() {
	string s;
	int n, m;
	int result = 987654321;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> s;
		chess.push_back(s);
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			result = MIN(result, MIN(changeW(j, i), changeB(j, i)));
		}
	}
	
	printf("%d\n", result);

	return 0;
}