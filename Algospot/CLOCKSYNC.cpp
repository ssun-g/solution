#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> clocks;

int MIN = 987654321;
int linked[10][16] = { 
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1}, 
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

bool alltwelve(vector<int>& arr) {
	for (int i = 0; i < 16; i++) {
		if (arr[i] != 12) return false;
	}
	return true;
}

void push(vector<int>& arr, int sw) {
	for (int i = 0; i < 16; i++) {
		if (linked[sw][i] == 1) {
			arr[i] += 3;
			if (arr[i] == 15) arr[i] = 3;
		}
	}
}

int solve(vector<int>& arr, int sw) {
	if (sw == 10) {
		if (alltwelve(arr)) return 0;
		else return 987654321;
	}
	int ret = MIN;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + solve(arr, sw + 1));
		push(arr, sw);
	}
	return ret;
}


int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		clocks.clear();
		for (int j = 0; j < 16; j++) {
			int c; 
			scanf("%d", &c);
			clocks.push_back(c);
		}
		int answer = solve(clocks, 0);
		if (answer == MIN) printf("-1\n");
		else printf("%d\n", answer);
	}
	return 0;
}