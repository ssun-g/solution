#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;

deque<int> StringToInt(string s) {
	string I = "";
	deque<int> dq;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') I += s[i];
		if (s[i] == ',') {
			dq.push_back(stoi(I));
			I = "";
		}
	}
	if (I != "") dq.push_back(stoi(I));

	return dq;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string command;
		cin >> command;
		int n;
		string num;
		cin >> n >> num;

		deque<int> dq = StringToInt(num);
		int flag = 1;
		bool isPass = false;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R')
				flag *= -1;
			else if (command[i] == 'D') {
				if (dq.empty()) {
					cout << "error" << '\n';
					isPass = true;
					break;
				}

				if (flag == -1) // reverse direction
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		// error is pass
		if (isPass) continue;

		string answer = "[";
		if (flag == 1) {
			while (!dq.empty()) {
				answer += to_string(dq.front());
				if (dq.size() != 1) answer += ",";
				dq.pop_front();
			}
		}
		else { // reverse direction
			while (!dq.empty()) {
				answer += to_string(dq.back());
				if (dq.size() != 1) answer += ",";
				dq.pop_back();
			}
		}
		answer += "]";
		cout << answer << '\n';
	}


	return 0;
}