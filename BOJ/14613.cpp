/*
지는 횟수 : lose
이기는 횟수 : win

브론즈: lose-win >= 11. 즉, 1000 ~ 501점을 잃어야 함.
실버: 1 <= lose-win < 11. 즉, 500 ~ 1점을 잃어야 함.
골드 :  0 <= win - lose < 10. 즉, 0 ~ 499점을 얻어야 함.
플래티넘 : 10 <= win-lose < 20. 즉, 500 ~ 999점을 얻어야 함.
다이아 : 20판 모두 이겨야 됨.

*/

#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
	if (n == 1 || n == 0) return 1;
	return n*factorial(n - 1);
}

int main() {
	double b = 0, s = 0, g = 0, p = 0, d = 0;
	double W, L, D;
	cin >> W >> L >> D;

	d = pow(W, 20);
	for (int draw = 0; draw <= 20; draw++) {
		for (int win = 0; win <= 20 - draw; win++) {
			int total_game = 20 - draw; // draw는 점수가 없으므로 draw한만큼 경기를 적게한 것과 같다.
			int lose = total_game - win; // 진 횟수 = 전체 경기 - 이긴 경기

			// win, lose, draw를 고르는 경우의 수이다. win + lose + draw = 20을 만족하는 연립방정식의 해의 집합.
			long long comb = factorial(20) / factorial(win) / factorial(lose) / factorial(draw);

			// 맨 처음 구해 놓았던 '해당 티어에 도달하기 위한 승리, 패배 횟수'에 만족하면 확률 값을 계산후 더해 주었다.
			if (lose - win >= 11) b += comb*pow(W, win)*pow(L, lose)*pow(D, draw);
			if (1 <= lose - win && lose - win < 11) s += comb*pow(W, win)*pow(L, lose)*pow(D, draw);
			if (0 <= win - lose && win - lose < 10) g += comb*pow(W, win)*pow(L, lose)*pow(D, draw);
			if (10 <= win - lose && win - lose < 20) p += comb*pow(W, win)*pow(L, lose)*pow(D, draw);
		}
	}

	cout << fixed;
	cout.precision(8); // 소수점 8자리 고정 후 출력 (9번째 자리에서 반올림)
	cout << b << '\n';
	cout << s << '\n';
	cout << g << '\n';
	cout << p << '\n';
	cout << d << '\n';

	return 0;
}
