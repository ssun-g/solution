#include <vector>
#include <map>
using namespace std;

map<int, int> mp;

int solution(vector<int> nums)
{
	int answer = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (mp.empty() || mp.find(nums[i]) == mp.end()) mp.insert(make_pair(nums[i], 1));
		else mp.find(nums[i])->second++;
	}
	if (nums.size() / 2 <= mp.size()) answer = nums.size() / 2;
	else answer = mp.size();

	return answer;
}