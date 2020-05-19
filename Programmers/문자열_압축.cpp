#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	int cnt = 1;
	if (s.length() == 1) return 1;
	for (int i = 1; i <= s.length() / 2; i++) {
		string st = "";
		string tmp = s.substr(0, i);
		for (int j = i; j < s.length(); j += i) {
			string cmp = s.substr(j, i);
			if (!tmp.compare(cmp)) cnt++;
			else {
				if (cnt == 1) st += tmp;
				else {
					st = st + to_string(cnt) + tmp;
					cnt = 1;
				}
				tmp = cmp;
			}
		}
		if (cnt == 1) st += tmp;
		else {
			st = st + to_string(cnt) + tmp;
			cnt = 1;
		}
		answer = (answer > st.length()) ? st.length() : answer;
	}
	return answer;
}