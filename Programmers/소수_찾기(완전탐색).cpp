#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int check[7];
int used[10000000];
int result;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

void dfs(int cnt, string numbers, string num) {
	if (cnt != 0 && !used[stoi(num)]) {
		used[stoi(num)] = 1;
		if (isPrime(stoi(num))) result++;
	}
	for (int i = 0; i < numbers.length(); i++) {
		if (!check[i]) {
			check[i] = 1;
			dfs(cnt + 1, numbers, num + numbers[i]);
			check[i] = 0;
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	dfs(0, numbers, "");
	answer = result;
	return answer;
}