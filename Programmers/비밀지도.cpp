#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> v;
	for (int i = 0; i < arr1.size(); i++) {
		v.push_back(arr1[i] | arr2[i]);
	}

	for (int i = 0; i < v.size(); i++) {
		string s = "";
		int k = n;
		while (k--) {
			if (v[i] == 0) s += ' ';
			else if (v[i] % 2 == 0) s += ' ';
			else s += '#';
			v[i] /= 2;
		}
		reverse(s.begin(), s.end());
		answer.push_back(s);
	}



	return answer;
}