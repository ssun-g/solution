#include <string>
#include <vector>
#define MIN(x,y) ((x<y)? x:y)
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int min = arr[0];
	if (arr.size() == 1) {
		answer.push_back(-1);
		return answer;
	};
	for (int i = 0; i < arr.size(); i++) {
		min = MIN(min, arr[i]);
	}
	for (int i = 0; i < arr.size(); i++) {
		if (min == arr[i]) arr[i] = 0;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) continue;
		answer.push_back(arr[i]);
	}
	return answer;
}