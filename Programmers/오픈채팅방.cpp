#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<pair<string, string> > enter;
unordered_map<string, string> ump;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	for (int i = 0; i < record.size(); i++) {
		stringstream ss;
		string command, id, name;
		ss << record[i];
		ss >> command >> id >> name;
		if (command == "Enter") {
			enter.push_back(make_pair(command, id));
			ump[id] = name;
		}
		else if (command == "Leave")
			enter.push_back(make_pair(command, id));
		else ump[id] = name;
	}

	for (int i = 0; i < enter.size(); i++) {
		if (enter[i].first == "Enter") answer.push_back(ump[enter[i].second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		else answer.push_back(ump[enter[i].second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
	}

	return answer;
}