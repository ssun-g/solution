#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Conv {
public:
	string st;
	int cutzero;

	Conv(string st, int cutzero) {
		this->st = st;
		this->cutzero = cutzero;
	}
};

Conv binaryConvert(string s) {
	int cut = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') cut++;
	}

	int len = s.length() - cut;
	string after = "";
	while (len) {
		after += (len % 2) + '0';
		len /= 2;
	}
	reverse(after.begin(), after.end());

	return Conv(after, cut);
}

vector<int> solution(string s) {
	vector<int> answer;
	string tmp = s;

	int cnt = 0;
	int zero = 0;
	while (true) {
		if (tmp == "1") break;
		Conv c = binaryConvert(tmp);

		tmp = c.st;
		zero += c.cutzero;
		cnt++;
	}
	answer.push_back(cnt);
	answer.push_back(zero);

	return answer;
}