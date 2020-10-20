#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ump;
vector<int> num;
vector<int> arr;


bool checkPrime(int num) {
	int cnt = 0;
	for (int j = 1; j <= sqrt(num); j++) {
		if (num%j == 0) cnt++;
		if (cnt > 1) return false;
	}
	if (cnt == 1) return true;
	else return false;
}

int solution(string numbers) {
	int answer = 0;
	for (int i = 0; i < numbers.length(); i++) {
		arr.push_back(numbers[i] - '0');
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < numbers.length(); i++) {
		do {
			string tmp = "";
			for (int j = 0; j <= i; j++) {
				tmp += to_string(arr[j]);
			}
			num.push_back(stoi(tmp));
		} while (next_permutation(arr.begin(), arr.end()));
	}

	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 2) continue;
		if (checkPrime(num[i]) && ump[num[i]] == 0) {
			answer++;
			ump[num[i]]++;
		}
	}

	return answer;
}