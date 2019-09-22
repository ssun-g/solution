#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
	if (m == 0) return n;
	else return gcd(m, n%m);
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	if (n > m) answer.push_back(gcd(n, m));
	else answer.push_back(gcd(m, n));

	answer.push_back(answer[0] * n / answer[0] * m / answer[0]);
	return answer;
}