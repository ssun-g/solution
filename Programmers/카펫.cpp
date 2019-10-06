#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int x, y;
	for (int i = 1; i*i <= red; i++) {
		if (red%i) continue;
		x = i;
		y = red / i;
		if (brown == ((x + 2)*(y + 2) - red)) {
			answer.push_back(y + 2);
			answer.push_back(x + 2);
		}
	}

	return answer;
}