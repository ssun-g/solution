#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	string s = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int num;
			cin >> num;
			if (num == 0) s += '9';
			else s += to_string(num);
		}
	}

	queue<string> q;
	unordered_map<string, int> ump;
	q.push(s);
	ump[s] = 0;

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (cur == "123456789") break;

		int z = cur.find('9');
		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				string next = cur;
				swap(next[y * 3 + x], next[ny * 3 + nx]);

				if (!ump.count(next)) {
					ump[next] = ump[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	if (!ump.count("123456789")) cout << -1 << '\n';
	else cout << ump["123456789"] << '\n';

	return 0;
}