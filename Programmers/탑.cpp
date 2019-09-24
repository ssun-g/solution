#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> tmp;
	for (int i = heights.size() - 1; i >= 0; i--) {
		if (i == 0) {
			tmp.push_back(i);
			break;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				tmp.push_back(j + 1);
				break;
			}
			if (j == 0) tmp.push_back(j);
		}
	}
	while (!tmp.empty()) {
		answer.push_back(tmp.back());
		tmp.pop_back();
	}
	return answer;
}