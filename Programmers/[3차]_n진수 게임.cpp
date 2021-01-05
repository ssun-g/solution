#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };

string convert(int d, int num) {
	string ret = "";
	while (num) {
		if (num%d >= 10) ret += arr[(num%d) % 10];
		else ret += to_string(num%d);

		num /= d;
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string tmp = "";

	// 0 ~ t*m 까지의 숫자를 이진법으로 변환 후 순서대로 tmp에 저장.
	for (int i = 0; i <= t*m; i++) {
		if (i >= n) tmp += convert(n, i);
		else if (i >= 10) tmp += arr[i % 10];
		else tmp += to_string(i);
	}

	// 인원 수를 고려하여 말해야 하는 숫자 t개를 골라준다.
	int cnt = 0;
	for (int i = p - 1; i < tmp.length(); i += m) {
		if (cnt == t) break;
		answer += tmp[i];
		cnt++;
	}

	return answer;
}