#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pqg;
priority_queue<int, vector<int> > pql;
unordered_map<int, int> ump;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	for (int i = 0; i < operations.size(); i++) {
		stringstream ss;
		string command, num;
		ss << operations[i];
		ss >> command >> num;

		if (command == "I") {
			pqg.push(stoi(num));
			pql.push(stoi(num));
		}
		else if (command == "D") {
			if (!pql.empty() && num == "1") {
				ump[pql.top()]++;
				while (!pql.empty() && ump[pql.top()] != 0) {
					pql.pop();
				}
				while (!pqg.empty() && ump[pqg.top()] != 0) {
					pqg.pop();
				}
			}
			else if (!pqg.empty() && num == "-1") {
				ump[pqg.top()]++;
				while (!pqg.empty() && ump[pqg.top()] != 0) {
					pqg.pop();
				}
				while (!pql.empty() && ump[pql.top()] != 0) {
					pql.pop();
				}
			}
		}
	}

	int MAX = 0, MIN = 0;
	while (!pql.empty()) {
		if (ump[pql.top()] == 0) {
			MAX = pql.top();
			break;
		}
		pql.pop();
	}

	while (!pqg.empty()) {
		if (ump[pqg.top()] == 0) {
			MIN = pqg.top();
			break;
		}
		pqg.pop();
	}
	answer.push_back(MAX);
	answer.push_back(MIN);

	return answer;
}